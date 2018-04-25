#!/usr/bin/env python3
import functools

a = {
    'A': 0,
    'A#': 1,
    'Bb': 1,
    'B': 2,
    'Cb': 2,
    'B#': 3,
    'C': 3,
    'C#': 4,
    'Db': 4,
    'D': 5,
    'D#': 6,
    'Eb': 6,
    'E': 7,
    'Fb': 7,
    'E#': 8,
    'F': 8,
    'F#': 9,
    'Gb': 9,
    'G': 10,
    'G#': 11,
    'Ab': 11,
}

M = ['MA', 'MA#', 'MB', 'MC', 'MC#', 'MD', 'MD#', 'ME', 'MF', 'MF#', 'MG', 'MG#']
m = ['mA', 'mA#', 'mB', 'mC', 'mC#', 'mD', 'mD#', 'mE', 'mF', 'mF#', 'mG', 'mG#']
d = [set() for _ in range(12)]
for i in range(12):
    for k in [0, 2, 4, 5, 7, 9, 11]:
        d[(i + k) % 12].add(M[i])
    for k in [0, 2, 3, 5, 7, 8, 10]:
        d[(i + k) % 12].add(m[i])
for t in range(int(input())):
    n = int(input())
    x = map(lambda x: d[a[x]], input().split()) if n > 0 else []
    s = functools.reduce(lambda x, y: x.intersection(y), x, set(M + m))
    print('Case #{}: {}'.format(t + 1, ' '.join(sorted(s)) if len(s) else 'None'))
              
