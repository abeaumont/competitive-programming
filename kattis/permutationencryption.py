# https://open.kattis.com/problems/permutationencryption
while True:
    xs = map(int, raw_input().split())
    n = xs[0]
    if n == 0: break
    xs = xs[1:]
    s = raw_input()
    mod = len(s) % n
    if mod > 0:
        s += ' ' * (n - mod)
    ys = [None] * len(s)
    for i in range(0, len(s), n):
        for j in range(n):
            ys[i + j] = s[i + xs[j] - 1]
    print "'" + ''.join(ys) + "'"
