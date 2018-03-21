#!/usr/bin/env python3
# https://abc051.contest.atcoder.jp/tasks/abc051_c
sx, sy, tx, ty = [int(x) for x in input().split()]
dx = tx - sx
dy = ty - sy
print('U' * dy + 'R' * dx + 'D' * dy + 'L' * dx + 'L' + 'U' * (dy + 1) + 'R' * (dx + 1) + 'D' + 'R' + 'D' * (dy + 1) + 'L' * (dx + 1) + 'U')
