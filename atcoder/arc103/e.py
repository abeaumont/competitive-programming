#!/usr/bin/env python3
# https://arc103.contest.atcoder.jp/tasks/arc103_c
def f(s):
    n = len(s)
    if s[-1] == '1' or s[-2] == '0' or s[0] == '0':
        print(-1)
        return
    i,j = 0,n-2
    while i < j:
        if s[i] != s[j]:
            print(-1)
            return
        i+=1
        j-=1
    e = []
    k = 0
    for i, c in enumerate(s):
        if c == '1':
            if i == 0:
                k = 0
                continue
            for j in range(k+1): e.append((i-k+j, i+1))
            k = 0
        else: k += 1
    e.append((n-k, n))
    for u,v in e: print(u,v)
f(input())
