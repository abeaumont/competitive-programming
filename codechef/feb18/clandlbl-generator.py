import random

def divisors(n):
    c = 0
    for divisor in range(1, n+1):
        if n % divisor == 0: c += 1
    return c

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

print 1
n = random.randrange(1, 10)
print n
a = random.sample(range(1, n + 1), n)
m = [None] * n
for i in range(n): m[i] = [0] * n
for i in range(n):
    for j in range(i + 1, n):
        k = divisors(gcd(a[i], a[j]))
        m[i][j] = k
        m[j][i] = k
for i in range(n): print ' '.join(map(str, m[i]))
print a
        
