#!/usr/bin/env python3
# https://abc084.contest.atcoder.jp/tasks/abc084_b
a, b = map(int, input().split())
s = input()
ok = True
for i in range(a):
    if s[i] == '-': ok = False
if s[a] != '-': ok = False
for i in range(a + 1, a + b + 1):
    if s[i] == '-': ok = False
if ok: print('Yes')
else: print('No')
