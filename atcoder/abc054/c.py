#!/usr/bin/env python3
# https://abc054.contest.atcoder.jp/tasks/abc054_c
def dfs(g, v, i):
    if len(v) == len(g) - 1: return 1
    v.add(i)
    c = 0
    for u in g[i]:
        if u not in v: c += dfs(g, v, u)
    v.remove(i)
    return c

n, m = map(int, input().split())
g = [list() for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)
print(dfs(g, set(), 0))
