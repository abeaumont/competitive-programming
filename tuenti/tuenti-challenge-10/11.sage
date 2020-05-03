#!/usr/bin/env sage
for t in range(int(input())):
    xs = [int(x) for x in input().split()]
    x = xs[0]
    ys = xs[1:]
    ps = Partitions(x)
    c = 0
    for p in ps:
        ok = True
        for y in ys:
            if y in p:
                ok = False
                break
        if ok:
            c += 1
    print(f'Case #{t+1}: {c-1}')
