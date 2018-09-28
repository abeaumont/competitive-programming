#!/usr/bin/env python3
# https://www.hackerrank.com/challenges/game-with-cells
n,m=map(int,input().split())
s=((n//2*2)*(m//2*2)-1)//4+1
if n%2==1: s+=m//2
if m%2==1: s+=n//2
if n%2==1 and m%2==1: s+=1
print(s)
