import intsets, random
randomize()
let n = 1 + random(9999)
let k = 1 + random(9)
var d = initIntSet()
for i in 1..k:
  while true:
    let j = random(10)
    if not d.contains(j):
      d.incl(j)
      break
var s = ""
for i in d:
  s.add($i & " ")
echo n, " ", k
echo s[0..<s.len-1]
