# https://atcoder.jp/contests/abc055/tasks/arc069_b
import strutils

let n = stdin.readLine().parseInt()
let s = stdin.readLine()
for c in @["SS", "SW", "WS", "WW"]:
  var r = newSeq[char](n)
  r[0] = c[0]
  r[1] = c[1]
  for i in 1..<n-1:
    if r[i] == 'S':
      if r[i-1] == 'S':
        if s[i] == 'o':
          r[i+1] = 'S'
        else:
          r[i+1] = 'W'
      else:
        if s[i] == 'o':
          r[i+1] = 'W'
        else:
          r[i+1] = 'S'
    else:
      if r[i-1] == 'S':
        if s[i] == 'o':
          r[i+1] = 'W'
        else:
          r[i+1] = 'S'
      else:
        if s[i] == 'o':
          r[i+1] = 'S'
        else:
          r[i+1] = 'W'
  if ((r[n-1] == 'S' and s[n-1] == 'o' and r[0] == r[n-2]) or
     (r[n-1] == 'S' and s[n-1] == 'x' and r[0] != r[n-2]) or
     (r[n-1] == 'W' and s[n-1] == 'o' and r[0] != r[n-2]) or
     (r[n-1] == 'W' and s[n-1] == 'x' and r[0] == r[n-2])) and
     ((r[0] == 'S' and s[0] == 'o' and r[n-1] == r[1]) or
     (r[0] == 'S' and s[0] == 'x' and r[n-1] != r[1]) or
     (r[0] == 'W' and s[0] == 'o' and r[n-1] != r[1]) or
     (r[0] == 'W' and s[0] == 'x' and r[n-1] == r[1])):
    echo r.join()
    quit()
echo -1
