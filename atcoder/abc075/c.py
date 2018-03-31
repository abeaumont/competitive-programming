#!/usr/bin/env python3
# https://abc075.contest.atcoder.jp/tasks/abc075_c
def dfs(g, s, u):
    s.add(u)
    if len(s) == len(g):
        return True
    for v in g[u]:
        if v not in s:
            if dfs(g, s, v):
                return True
    return False

n, m = map(int, input().split())
e = []
for _ in range(m):
    a, b = map(int, input().split())
    e.append((a - 1, b - 1))
c = 0
for i in range(m):
    g = [list() for _ in range(n)]
    for j in range(len(e)):
        if j == i: continue
        a, b = e[j]
        g[a].append(b)
        g[b].append(a)
    if not dfs(g, set(), 0): c += 1
print(c)
