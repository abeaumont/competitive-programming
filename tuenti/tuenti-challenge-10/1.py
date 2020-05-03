#!/usr/bin/env python
for i in range(int(input())):
    k = ''.join(sorted(input().split()))
    s = {'PP': '-', 'PR': 'P', 'PS': 'S', 'RR': '-', 'RS': 'R', 'SS': '-'}
    print(f'Case #{i+1}: {s[k]}')
