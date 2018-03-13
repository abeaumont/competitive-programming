# https://abc078.contest.atcoder.jp/tasks/arc085_a
n, m = map(int, raw_input().split())
k = n - m
a = pow(2, m)
print (k * 100 + 1900 * m) * a
