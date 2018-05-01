#!/usr/bin/env sage
def t(a, p, e):
    b = pow(p, e)
    if p == 2:
        if a == 0: return 2
        if a % 4 == 1: return b / gcd(a - 1, b)
        if a % 4 == 3: return b / gcd(a + 1, b)
    if p == 5:
        if a % 5 == 1: return b / gcd(a - 1, b)
        if a % 5 == 4: return 2 * b / gcd(a + 1, b)
        if a % 5 == 2: return 4 * b / gcd(a * a + 1, b)
        if a % 5 == 3: return 4 * b / gcd(a * a + 1, b)
    if a % p == 1: return b / gcd(a - 1, b)
    if a % p == p - 1: return 2 * b / gcd(a + 1, b)

for T in range(int(raw_input())):
    x, a, c, m = map(int, raw_input().split())
    d = gcd(x * (a - 1) + c, m)
    q = []
    for p, e in factor(m/d):
        k = pow(p, e)
        try:
            l = t(a, p, e)
            if l is None:
                l = Mod(a, k).multiplicative_order()
        except:
            l = 1
        q.append(gcd(a - 1, k) * l)
    p = lcm(q)
    ap = int(pow(a, int(p), m * (a - 1)))
    xn = (ap * x + (ap - 1) * c / (a - 1)) % m
    while xn != x:
        p += 1
        x = (x * a + c) % m
        xn = (xn * a + c) % m
    print('Case #{}: {}'.format(T + 1, p + 1))
