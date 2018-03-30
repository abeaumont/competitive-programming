#!/usr/bin/env python3
# https://abc062.contest.atcoder.jp/tasks/abc062_b
h, w = map(int, input().split())
print('#' * (w + 2))
for _ in range(h): print('#' + input() + '#')
print('#' * (w + 2))
