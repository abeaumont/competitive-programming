#!/usr/bin/env python3
from random import randint as r
t=20
print(t)
for _ in range(t):
    n,m=r(1,6),r(1,6)
    print(n,m)
    for _ in range(2):
        x1=r(1,m)
        y1=r(1,n)
        x2=r(x1,m)
        y2=r(y1,n)
        print(x1,y1,x2,y2)
    
