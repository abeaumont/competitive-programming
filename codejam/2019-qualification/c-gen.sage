#!/usr/bin/sage
import random
import string
import sys
t=100
print(t)
for _ in range(t):
    p=set([3])
    while(len(p)!=26):
        p.add(next_prime(random.randint(10**99,10**100)))
    p=sorted(list(p))
    m=[x for x in string.ascii_uppercase*random(1,4)]
    random.shuffle(m)
    x=[]
    for i in range(len(m)-1):
        a,b=ord(m[i])-ord('A'),ord(m[i+1])-ord('A')
        x.append(p[a]*p[b])
    print('{} {}'.format(max(p),len(m)-1))
    print(' '.join(map(str,x)))
