# https://abc080.contest.atcoder.jp/tasks/abc080_b
n = input()
ds = str(n)
s = 0
for d in ds:
    s += int(d)
if n % s == 0:
    print 'Yes'
else:
    print 'No'
