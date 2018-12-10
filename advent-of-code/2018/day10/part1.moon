max = (xs) ->
  m = 0
  for x in *xs do m = math.max m, x
  m

min = (xs) ->
  m = math.maxinteger
  for x in *xs do m = math.min m, x
  m

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
  d = max(ys) - min(ys)
  if not m or d < m then m = d else break
  i += 1
i -= 1
xs = [x + vx * i for {x,_,vx,_} in *p]
ys = [y + vy * i for {_,y,_,vy} in *p]
mx, Mx, my, My = min(xs), max(xs), min(ys), max(ys)
m = [[' ' for _=1,Mx-mx+1] for _=1,My-my+1]
for {x,y,vx,vy} in *p do m[y+vy*i-my+1][x+vx*i-mx+1] = '#'
for r in *m do print table.concat(r)
