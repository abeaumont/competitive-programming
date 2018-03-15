import random

t = 100
print t
for _ in range(t):
    l = random.randint(1, 10000)
    print ''.join([chr(random.randint(33, 122)) for i in range(l)])
