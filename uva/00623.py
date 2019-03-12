#!/usr/bin/env python3
# https://uva.onlinejudge.org/external/6/623.pdf
while True:
    try:
        n=int(input())
        print(str(n)+'!')
        k=1
        for i in range(1,n+1):k*=i
        print(k)
    except:break
