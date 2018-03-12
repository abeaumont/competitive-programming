import random
n = random.randint(1, 100)
q = random.randint(1, 100)
print n
print ' '.join([str(random.randint(1, 100000)) for _ in range(n)])
print q
for _ in range(q):
    t = random.randint(1, 2)
    if t == 1:
        x = random.randint(1, n)
        y = random.randint(1, 100000)
        print 1, x, y
    else:
        l = random.randint(1, n - 1)
        r = random.randint(l, n)
        g = random.randint(1, 100000)
        print 2, l, r, g
