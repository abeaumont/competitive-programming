# https://abc086.contest.atcoder.jp/tasks/arc089_a
import sys

t, x, y = 0, 0, 0
for _ in range(input()):
    [t2, x2, y2] = map(int, raw_input().split())
    d1 = abs(x2 - x) + abs(y2 - y)
    d2 = t2 - t
    if d1 > d2:
        print 'No'
        sys.exit(0)
    if d1 == d2 or (d2 - d1) % 2 == 0:
        t = t2
        x = x2
        y = y2
    else:
        print 'No'
        sys.exit(0)
        
print 'Yes'
