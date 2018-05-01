#!/usr/bin/sage
for c in range(input()):
    m, r = [], []
    for i in range(input()):
        p, t = map(int, raw_input().split())
        m.append((p - t - i) % p)
        r.append(p)
    try:
        r = crt(m, r)
    except:
        r = 'NEVER'
    print('Case #{}: {}'.format(c + 1, r))
