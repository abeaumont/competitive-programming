#!/usr/bin/env python3
a = [None] * 2500
a[1:6] = [1, 2, 10, 46, 212, 982]
b = [7, -13, 10, -4, 5, -2]
for i in range(7, 2501):
    a[i] = sum([b[j] * a[i - j - 1] for j in range(len(b))]) % (10**9 + 7)
for i in range(int(input())):
    print('Case #{}: {}'.format(i + 1, a[int(input())]))
