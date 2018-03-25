#!/usr/bin/env python3
# https://abc092.contest.atcoder.jp/tasks/arc093_b
a, b = map(int, input().split())
z = True
y = 0
s = ''
while a >= 50:
  x = 100
  s += '#.' * 50 + '\n'
  s += '#' * 99 + '.\n'
  y += 2
  a -= 49
s += '.#' * (a - 1) + '##' * (50 - a) + '#.\n'
s += '#' * 99 + '.\n'
s += '.' * 100 + '\n'
y += 3
b -= 1
while b >= 50:
  x = 100
  s += '#.' * 50 + '\n'
  s += '.' * 100 + '\n'
  y += 2
  b -= 50
s += '#.' * b + '..' * (50 - b)
y += 1
print(y, 100)
print(s)
