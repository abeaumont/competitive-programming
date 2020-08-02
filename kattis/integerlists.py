# https://open.kattis.com/problems/integerlists
#!/usr/bin/env python3
for _ in range(int(input())):
    p = input()
    n = int(input())
    i, j = 0, n
    xs = input()[1:-1].split(',')
    front = True
    for c in p:
        if c == 'R':
            front = not front
        elif i == j:
            i += 1
            break
        elif front:
            i += 1
        else:
            j -= 1
    if i > j:
        print('error')
    else:
        if front:
            print('[' + ','.join(xs[i:j]) + ']')
        else:
            print('[' + ','.join(xs[i:j][::-1]) + ']')
