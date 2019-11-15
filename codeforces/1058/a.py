#!/usr/bin/env python3
# https://codeforces.com/contest/1058/problem/A
n = int(input())
x = sum([int(x) for x in input().split()])
if x == 0: print('EASY')
else: print('HARD')
