# https://open.kattis.com/problems/flexible
k = int(raw_input().split()[0])
xs = [0] + map(int, raw_input().split()) + [k]

s = set()
for i in range(len(xs) - 1):
    c = 0
    for j in range(i, len(xs) - 1):
        c += xs[j+1] - xs[j]
        s.add(c)

xs = xs[::-1]
for i in range(len(xs) - 1):
    c = 0
    for j in range(i, len(xs) - 1):
        c += xs[j] - xs[j+1]
        s.add(c)
print ' '.join(map(str, sorted(s)))
