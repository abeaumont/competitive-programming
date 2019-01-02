#!/usr/bin/lua
-- Since this grammar is ambigous, keep it simple while being compliant with
-- bot test and final cases

function trim(s)
   return (s:gsub("^%s*(.-)%s*$", "%1"))
end

function check(p, s)
   p_start = 1
   s_start = 1
   strict = true
   while s_start < s:len() and p_start < p:len() do
      p_stop = p:find('[*!?^]', p_start)
      if p_stop == nil then
         if strict then
            return s:sub(s_start) == p:sub(p_start)
         else
            len = p:len() - p_start
            pos = s:find(p:sub(p_start), s_start)
            if pos == nil then
               return false
            elseif pos + len == s:len() then
               return true
            else
               return false
            end
         end
      end
      pos = s:find(p:sub(p_start, p_stop - 1), s_start)
      if pos == nil then
         return false
      elseif strict and pos ~= s_start then
         return false
      end
      s_start = pos + p_stop - p_start
      if p:sub(p_stop, p_stop) == '!' then
         len = p:find('!', p_stop + 1) - (p_stop + 1)
         pos = s:find(p:sub(p_stop + 1, p_stop + len), s_start)
         if pos ~= nil then
            return false
         end
         p_start = p_stop + len + 2
         strict = false
      elseif p:sub(p_stop, p_stop) == '^' then
         pos = s:find('[A-Z]', s_start)
         if pos == nil then
            return false
         elseif strict and pos ~= s_start then
            return false
         end
         s_start = pos + 1
         p_start = p_stop + 1
      elseif p:sub(p_stop, p_stop) == '?' then
         s_start = s_start + 1
         p_start = p_stop + 1
      elseif p:sub(p_stop, p_stop) == '*' then
         if p:len() == p_stop then
            return true
         end
         strict = false
         p_start = p_stop + 1
      end
   end
   return true
end

pattern = io.read("*line")
while pattern do
   if check(trim(pattern), trim(io.read("*line"))) then
      print('y')
   else
      print('n')
   end
   pattern = io.read("*line")
end
