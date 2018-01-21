# https://abc086.contest.atcoder.jp/tasks/abc086_b
import math
a = int(''.join(raw_input().split()))
b = int(math.sqrt(a))
if b * b == a:
    print 'Yes'
else:
    print 'No'
