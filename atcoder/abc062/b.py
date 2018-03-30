#!/usr/bin/env python3
# https://beta.atcoder.jp/contests/abc062/tasks/abc062_b
h, w = map(int, input().split())
print('#' * (w + 2))
for _ in range(h): print('#' + input() + '#')
print('#' * (w + 2))
