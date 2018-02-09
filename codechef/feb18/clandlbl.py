# https://www.codechef.com/FEB18/problems/CLANDLBL
def divisors(n):
    c = 0
    for divisor in range(1, n+1):
        if n % divisor == 0: c += 1
    return c

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

for _ in range(input()):
    n = input()
    g = {}
    h = [None] * n
    r = [None] * n
    for i in range(n):
        h[i] = map(int, raw_input().split())
        key = tuple(sorted(h[i]))
        if key in g:
            g[key].append(i)
        else:
            g[key] = [i]
    a = {}
    m = [None] * n
    for i in range(n):
        m[i] = [0] * n
    for i in range(n):
        for j in range(i + 1, n):
            m[i][j] = divisors(gcd(j + 1, i + 1))
            m[j][i] = m[i][j]
    for i in range(n):
        key = tuple(sorted(m[i]))
        if key in a: a[key].append(i)
        else: a[key] = [i]
    s = [(len(v), k) for k, v in a.iteritems()]
    s.sort()
    l = set()
    hi = [None] * n
    for _, k in s:
        if len(a[k]) == 1:
            x = a[k][0]
            y = g[k][0]
            r[y] = x
            hi[x] = y
            l.add(x)
        else:
            t = set()
            for x in a[k]:
                for y in g[k]:
                    if y in t: continue
                    ok = True
                    for z in l:
                        if m[x][z] != h[y][hi[z]]:
                            ok = False
                            break
                    if ok:
                        r[y] = x
                        hi[x] = y
                        l.add(x)
                        t.add(y)
                        break
    for i in r: print i + 1
