#!/usr/bin/env python3
# https://beta.atcoder.jp/contests/abc062/tasks/abc062_a
x, y = map(int, input().split())
s = [4, 6, 9, 11]
if x in s and y in s: print('Yes')
elif x in s or y in s: print('No')
elif x == 2 or y == 2: print('No')
else: print('Yes')
