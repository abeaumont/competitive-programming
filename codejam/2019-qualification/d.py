#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881de
t=int(input())
for _ in range(t):
    n,b,f=map(int,input().split())
    r=[None]*10
    for i in range(f):
        s=('1'*(2**(f-i-1))+'0'*(2**(f-i-1)))*(2**i)
        s=s[-n:]
        print(s)
        r[i]=input()
        if int(r[i])==-1:break
    if r[-1] is None: break
    x=[True]*n
    for i in range(n-b):
        x[int(''.join([r[j][i] for j in range(f)]),2)]=False
    x=sorted([n-i-1 for i,k in enumerate(x) if k])
    print(' '.join(map(str,x)))
    if int(input())==-1:
        break
