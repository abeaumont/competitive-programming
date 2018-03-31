#!/usr/bin/env python3
# https://abc075.contest.atcoder.jp/tasks/abc075_b
h, w = map(int, input().split())
s = []
for _ in range(h):
    s.append(input())
v = []
for _ in range(h):
    v.append([0] * w)
for i in range(h):
    for j in range(w):
        if s[i][j] == '#':
            v[i][j] = '#'
        else:
            c = 0
            if i > 0: c += s[i - 1][j] == '#'
            if j > 0: c += s[i][j - 1] == '#'
            if i < h - 1: c += s[i + 1][j] == '#'
            if j < w - 1: c += s[i][j + 1] == '#'
            if i > 0 and j > 0: c += s[i - 1][j - 1] == '#'
            if i > 0 and j < w - 1: c += s[i - 1][j + 1] == '#'
            if i < h - 1 and j > 0: c += s[i + 1][j - 1] == '#'
            if i < h - 1 and j < w - 1: c += s[i + 1][j + 1] == '#'
            v[i][j] = str(c)
    print(''.join(v[i]))
