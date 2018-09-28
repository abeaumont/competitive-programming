#!/usr/bin/env python3
# https://www.hackerrank.com/challenges/find-point
for _ in range(int(input())):
    px,py,qx,qy = map(int, input().split())
    rx,ry=2*qx-px,2*qy-py
    print(rx,ry)
