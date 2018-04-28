#!/usr/bin/env python3
import socket, sys

def r(f):
  line = f.readline()[:-1]
  print(line)
  return line

def w(f, s):
  print(s)
  f.write(s+'\n')
  f.flush()

c = None

def t(a, x, y, p, q, n, m, s):
    global c
    if n == m:
        c = sorted(map(lambda x: x + 1, x + y))
        return True
    for i in range(len(a)):
        if i in s: continue
        if n < m:
            ok = True
            for j in range(min(len(a[i]), m - n)):
                if a[i][j] != q[n + j]:
                    ok = False
                    break
            if ok:
                x.append(i)
                s.add(i)
                if t(a, x, y, p + a[i], q, n + len(a[i]), m, s): return True
                s.remove(i)
                x.pop()
        else:
            ok = True
            for j in range(min(len(a[i]), n - m)):
                if a[i][j] != p[m + j]:
                    ok = False
                    break
            if ok:
                y.append(i)
                s.add(i)
                if t(a, x, y, p, q + a[i], n, m + len(a[i]), s): return True
                s.remove(i)
                y.pop()

def s(a):
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            l1 = len(a[i])
            l2 = len(a[j])
            l = min(l1, l2)
            if a[i][:l] == a[j][:l]:
                if t(a, [i], [j], a[i], a[j], len(a[i]), len(a[j]), {i, j}): return True
    return False

sd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sd.connect(('52.49.91.111', 3241))
f = sd.makefile()
for i in range(2): r(f)
w(f, 'TEST' if len(sys.argv) > 1 else 'SUBMIT')
for _ in range(20):
    r(f)
    s(r(f).split())
    w(f, ','.join(map(str, c)))
r(f)
