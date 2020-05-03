#!/usr/bin/env python3
import sys
from pwn import remote
s = set()
y, x = 0, 0

r = remote('52.49.91.111', '2003')


def move(dy, dx, found):
    cmd = f"{abs(dy)}{'U' if dy < 0 else 'D'}{abs(dx)}{'L' if dx < 0 else 'R'}\n"
    r.send(cmd)
    if found:
        print(r.readall().decode('ascii'), end='')
        sys.exit()
    m = []
    for _ in range(5):
        m.append(r.readline().decode('ascii')[:-1])
    r.readline()
    r.readline()
    return m


def dfs(y, x, m):
    s.add((y, x))
    ys = [-2, -2, -1, -1, 1, 1, 2, 2]
    xs = [-1, 1, -2, 2, -2, 2, -1, 1]
    found = False
    for dy, dx in zip(ys, xs):
        my, mx = dy + 2, dx + 2
        if m[my][mx] == '#':
            continue
        if m[my][mx] == 'P':
            found = True
        ny, nx = y + dy, x + dx
        if (ny, nx) in s:
            continue
        dfs(ny, nx, move(dy, dx, found))
        move(-dy, -dx, found)


m = []
for _ in range(5):
    m.append(r.readline().decode('ascii')[:-1])
r.readline()
dfs(0, 0, m)
