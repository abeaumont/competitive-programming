#!/usr/bin/env python3
for i in range(int(input())):
    n = int(input())
    if n < 20 or (n >= 30 and n < 40) or n == 59:
        print(f'Case #{i+1}: IMPOSSIBLE')
    else:
        print(f'Case #{i+1}: {n//20}')
