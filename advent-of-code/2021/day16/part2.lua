#!/usr/bin/env lua
local hex = {}
function hextable()
   local s = '0123456789abcdef'
   for i = 1, #s  do
      hex[string.byte(s, i)] = i-1
   end
end

function hex2bin(s)
   local bin = {}
   for i = 1, #s do
      x = hex[string.byte(s, i)]
      bin[#bin+1] = x >> 3
      bin[#bin+1] = (x >> 2) & 1
      bin[#bin+1] = (x >> 1) & 1
      bin[#bin+1] = x & 1
   end
   return bin
end

function bits2dec(bits, i, k)
   local n = 0
   for j = i, i + k - 1 do
      n = n * 2 + bits[j]
   end
   return n
end

function parse_version(bits, i)
   return bits2dec(bits, i, 3), i + 3
end

function parse_type(bits, i)
   local types = {'sum', 'prod', 'min', 'max', 'number', 'gt', 'lt', 'eq'}
   local t = bits2dec(bits, i, 3)
   return types[t + 1], i + 3
end

function parse_number(bits, i)
   local n = 0
   while true do
      n = n * 16 + bits2dec(bits, i + 1, 4)
      if bits[i] == 0 then
         break
      else
         i = i + 5
      end
   end
   return n, i + 5
end

function parse_operator(bits, i)
   local op = {}
   if bits[i] == 0 then
      local len = bits2dec(bits, i + 1, 15)
      i = i + 16
      j = i
      repeat
         op[#op+1], j = parse(bits, j)
      until j == i + len
      i = j
   else
      local count = bits2dec(bits, i + 1, 11)
      i = i + 12
      for j = 1, count do
         op[j], i = parse(bits, i)
      end
   end
   return op, i
end

function parse(bits, i)
   local e = {}
   e.version, i = parse_version(bits, i)
   e.type, i = parse_type(bits, i)
   if e.type == 'number' then
      e.value, i = parse_number(bits, i)
   else
      e.op, i = parse_operator(bits, i)
   end
   return e, i
end

function eval(t)
   local r
   if t.type == 'sum' then
      r = 0
      for k = 1, #t.op do
         r = r + eval(t.op[k])
      end
   elseif t.type == 'prod' then
      r = 1
      for k = 1, #t.op do
         r = r * eval(t.op[k])
      end
   elseif t.type == 'min' then
      r = eval(t.op[1])
      for k = 2, #t.op do
         local s = eval(t.op[k])
         if s < r then
            r = s
         end
      end
   elseif t.type == 'max' then
      r = eval(t.op[1])
      for k = 2, #t.op do
         local s = eval(t.op[k])
         if s > r then
            r = s
         end
      end
   elseif t.type == 'number' then
      r = t.value
   elseif t.type == 'gt' then
      if eval(t.op[1]) > eval(t.op[2]) then
         r = 1
      else
         r = 0
      end
   elseif t.type == 'lt' then
      if eval(t.op[1]) < eval(t.op[2]) then
         r = 1
      else
         r = 0
      end
   else
      if eval(t.op[1]) == eval(t.op[2]) then
         r = 1
      else
         r = 0
      end
   end
   return r
end

hextable()
t = parse(hex2bin(string.lower(io.read())), 1)
print(eval(t))
