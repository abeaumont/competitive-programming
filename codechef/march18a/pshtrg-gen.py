import random
n = random.randint(1, 100)
q = random.randint(1, 100)
print n, q
print ' '.join([str(random.randint(1, 1000000000)) for _ in range(n)])
for _ in range(q):
    t = random.randint(1, 2)
    if t == 1:
        x = random.randint(1, n)
        y = random.randint(1, 1000000000)
        print 1, x, y
    else:
        l = random.randint(1, n - 1)
        r = random.randint(l, n)
        print 2, l, r
