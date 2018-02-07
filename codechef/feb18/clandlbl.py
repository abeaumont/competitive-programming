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
    g = [None] * n
    for i in range(n):
        g[i] = tuple(sorted(map(int, raw_input().split())))
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
    for x in g:
        print a[x].pop() + 1
