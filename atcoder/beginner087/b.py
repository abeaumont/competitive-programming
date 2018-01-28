# https://abc087.contest.atcoder.jp/tasks/abc087_b
a = input()
b = input()
c = input()
x = input()

cache = {}

def d(a, b, c, r):
    if r == 0: return 1
    if r < 0: return 0
    if cache.has_key((a, b, c, r)): return cache[(a, b, c, r)]
    s = 0
    if a > 0: s += d(a - 1, b, c, r - 500)
    if b > 0: s += d(0, b - 1, c, r - 100)
    if c > 0: s += d(0, 0, c - 1, r - 50)
    cache[(a, b, c, r)] = s
    return s

print d(a, b, c, x)
