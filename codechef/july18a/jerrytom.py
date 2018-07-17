#!/usr/bin/env python3
# https://www.codechef.com/JULY18A/problems/JERRYTOM
def max_clique(g):
    n = 0
    for x in g: n = max(n, len(x))
    l = [set() for _ in range(n + 1)]
    s = [0] * len(g)
    for i, x in enumerate(g):
        ll = len(x)
        l[ll].add(i)
        s[i] = ll
    m = 0
    for _ in range(len(g)):
        for i in range(n + 1):
            if len(l[i]) > 0:
                x = l[i].pop()
                m = max(m, i)
                s[x] = 0
                for k in g[x]:
                    if s[k] > 0:
                        l[s[k]].remove(k)
                        s[k] -= 1
                        l[s[k]].add(k)
                break
    return m + 1
    
def dfs(s, b, u):
    s.add(u)
    b[u] = True
    for v in g[u]:
        if b[v]: continue
        dfs(s, b, v)

for _ in range(int(input())):
    n, m = map(int, input().split())
    g = [list() for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        g[u-1].append(v-1)
        g[v-1].append(u-1)
    print(max_clique(g))
