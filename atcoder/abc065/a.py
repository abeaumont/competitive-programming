#!/usr/bin/env python3
# https://abc065.contest.atcoder.jp/tasks/abc065_a
x, a, b = map(int, input().split())
if b <= a: print('delicious')
elif b <= a + x: print('safe')
else: print('dangerous')
