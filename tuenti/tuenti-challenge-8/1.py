#!/usr/bin/env python3
for i in range(int(input())):
    n, m = map(int, input().split())
    print('Case #{}: {}'.format(i + 1, (n - 1) * (m - 1)))
