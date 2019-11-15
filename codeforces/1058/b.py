#!/usr/bin/env python3
# https://codeforces.com/contest/1058/problem/B
n,d=map(int, input().split())
for _ in range(int(input())):
    x,y=map(int, input().split())
    y1,y2,y3,y4 = d-x,2*n-d-x,d+x,x-d

    if y>=y1 and y<=y2 and y<=y3 and y>=y4: print('YES')
    else: print('NO')
