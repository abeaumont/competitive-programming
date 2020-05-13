#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
t, b = map(int, input().split())
for _ in range(t):
    xs = [None] * b
    q, k, k1, k2 = 0, 0, None, None

    def query(k):
        global q
        q += 1
        print(k)
        r = int(input())
        return r

    def complement():
        global xs
        for i in range(b):
            if xs[i] == 0:
                xs[i] = 1
            elif xs[i] == 1:
                xs[i] = 0

    def solve():
        print(''.join(str(x) for x in xs))
        assert(input() == 'Y')

    while True:
        if q > 0 and q % 10 == 0:
            if k1 is not None and k2 is not None:
                v1 = query(k1+1)
                v2 = query(k2+1)
                if xs[k1] == v1 and xs[k2] == v2:
                    pass
                elif xs[k1] != v1 and xs[k2] != v2:
                    complement()
                elif xs[k1] != v1:
                    xs = xs[::-1]
                    complement()
                else:
                    xs = xs[::-1]
            elif k1 is not None:
                v1 = query(k1+1)
                v1 = query(k1+1)
                if xs[k1] != v1:
                    complement()
            else:
                v2 = query(k2+1)
                v2 = query(k2+1)
                if xs[k2] != v2:
                    xs = xs[::-1]
        else:
            v1 = query(k+1)
            v2 = query(b-k)
            xs[k] = v1
            xs[b-k-1] = v2
            if v1 == v2 and k1 is None:
                k1 = k
            elif v1 != v2 and k2 is None:
                k2 = k
            k += 1
        if k*2 == b:
            solve()
            break
