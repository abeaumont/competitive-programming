#!/usr/bin/env python3
import math
import numpy as np
from fractions import Fraction
from scipy.sparse import csgraph, csr_matrix
from scipy.spatial import KDTree, Voronoi, distance

e = 1e-9

for T in range(int(input())):
    n = int(input())
    a = [None] * n
    for i in range(n):
        a[i] = [int(x) for x in input().split()]
    v = Voronoi(a)
    r = Fraction(input())
    s = [float(Fraction(x)) for x in input().split()]
    t = [float(Fraction(x)) for x in input().split()]
    b = v.vertices
    k = len(b)
    m = [[None] * (k + 2) for _ in range(k + 2)]
    c = KDTree(a)
    x = c.query(s, k=4)
    if x[0][0] - x[0][3] < e:
        sa, sb = None, None
    elif x[0][0] - x[0][1] < e:
        sa, sb = x[1]
    else:
        print('Case #{}: IMPOSSIBLE'.format(T + 1))
        continue
    x = c.query(t, k=4)
    if x[0][0] - x[0][3] < e:
        ta, tb = None, None
    elif x[0][0] - x[0][1] < e:
        ta, tb = x[1]
    else:
        print('Case #{}: IMPOSSIBLE'.format(T + 1))
        continue
    for p, q in zip(v.ridge_vertices, v.ridge_points):
        y, z = p
        if set([sa, sb]) == set(q):
            if y >= 0:
                d = distance.pdist([s, b[y]])[0]
                m[y][k] = d
                m[k][y] = d
            if z >= 0:
                d = distance.pdist([s, b[z]])[0]
                m[z][k] = d
                m[k][z] = d
        if set([ta, tb]) == set(q):
            if y >= 0:
                d = distance.pdist([t, b[y]])[0]
                m[y][k + 1] = d
                m[k + 1][y] = d
            if z >= 0:
                d = distance.pdist([t, b[z]])[0]
                m[z][k + 1] = d
                m[k + 1][z] = d
        if y >= 0 and z >= 0:
            if distance.pdist([a[i] for i in q])[0] >= 2 * r:
                d = distance.pdist([b[y], b[z]])[0]
                m[y][z] = d
                m[z][y] = d
    if sa is None or ta is None:
        for i, p in enumerate(b):
            if sa is None and abs(p[0] - s[0]) < e and abs(p[1] - s[1]) < e:
                m[i][k] = e
                m[k][i] = e
            if ta is None and abs(p[0] - t[0]) < e and abs(p[1] - t[1]) < e:
                m[i][k + 1] = e
                m[k + 1][i] = e
    m = csr_matrix(np.array(m), dtype=float)
    d = csgraph.shortest_path(m, directed=False, indices=[k, k + 1])[0][k+1]
    if d == np.inf: print('Case #{}: IMPOSSIBLE'.format(T + 1))
    else: print('Case #{}: {:.3f}'.format(T + 1, d))
