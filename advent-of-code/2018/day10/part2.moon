p = {}
i = 1
while true
  l = io.read()
  break if not l
  x, y, vx, vy = string.match(l, '<%s*(-?%d+),%s*(-?%d+)>.*<%s*(-?%d+),%s*(-?%d+)>')
  p[i] = {x, y, vx, vy}
  i += 1
i = 0
m = nil
while true
  ys = [y + vy * i for {_,y,_,vy} in *p]
  min, max = math.maxinteger, 0
  for y in *ys do max = math.max max, y
  for y in *ys do min = math.min min, y
  d = max - min
  if not m or d < m then m = d else break
  i += 1
print i - 1
