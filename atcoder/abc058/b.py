#!/usr/bin/env python3
# https://abc058.contest.atcoder.jp/tasks/abc058_b
o = input()
e = input()
x = []
for i in range(len(e)):
    x.append(o[i])
    x.append(e[i])
if len(o) > len(e): x.append(o[-1])
print(''.join(x))
