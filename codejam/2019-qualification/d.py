#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881de
t=int(input())
for _ in range(t):
    n,b,f=map(int,input().split())
    r=[None]*4
    z=[None]*(n-b)
    ok=True
    for i in range(5):
        a=16//(2**i)
        s=('0'*a+'1'*a)*(1024//(2*a))
        s=s[:n]
        print(s)
        q=input()
        if int(q)==-1:
            ok=False
            break
        if i:r[i-1]=q
        else:
            j,k=0,0
            while j<len(q) and k<n:
                if q[j]==s[k]:
                    z[j]=(k//16)*16
                    j+=1
                k+=1
    for i in range(f-5):
        if not ok:break
        s='0'*n
        print(s)
        if int(input())==-1:
            ok=False
            break
    if not ok:break
    x=[True]*n
    for i in range(n-b):
        x[z[i]+int(''.join([r[j][i] for j in range(4)]),2)]=False
    x=sorted([i for i,k in enumerate(x) if k])
    print(' '.join(map(str,x)))
    if int(input())==-1:
        break
