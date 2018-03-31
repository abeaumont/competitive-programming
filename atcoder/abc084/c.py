#!/usr/bin/env python3
# https://abc084.contest.atcoder.jp/tasks/abc084_c
n = int(input()) - 1
c, s, f = [0] * n, [0] * n, [0] * n
for i in range(n):
    c[i], s[i], f[i] = map(int, input().split())
for i in range(n):
    t = s[i] + c[i]
    for j in range(i + 1, n):
        if t <= s[j]:
            t = s[j]
        else:
            if t % f[j]:
                t += f[j] - (t % f[j])
        t += c[j]
    print(t)
print(0)
