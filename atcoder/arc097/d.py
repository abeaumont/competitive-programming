#!/usr/bin/env python3
# https://arc097.contest.atcoder.jp/tasks/arc097_b
import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, [0x10000000, resource.RLIM_INFINITY])
sys.setrecursionlimit(100000)

n, m = map(int, input().split())
p = [int(x) - 1 for x in input().split()]
g = [list() for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)
v = [False] * n
s = set()
def dfs(i):
    if v[i]: return
    s.add(i)
    v[i] = True
    for k in g[i]: dfs(k)

c = 0
for i in range(n):
    if v[i]: continue
    s = set()
    dfs(i)
    for k in s:
        if p[k] in s: c += 1
print(c)
