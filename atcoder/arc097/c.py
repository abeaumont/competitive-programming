#!/usr/bin/env python3
# https://arc097.contest.atcoder.jp/tasks/arc097_a
s = input()
k = int(input())
t = set()
for i in range(1, min(len(s), k, 5) + 1):
  for j in range(len(s) - i + 1):
	  t.add(s[j:i + j])
print(sorted(list(t))[k - 1])
