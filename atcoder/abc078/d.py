# https://abc078.contest.atcoder.jp/tasks/arc085_b
import sys

sys.setrecursionlimit(10000)

cm = None
cM = None
def m(a, n, i, w):
    if w in cm[i]: return cm[i][w]
    m = abs(a[n - 1] - w)
    for k in range(i, n - 1):
        m = min(m, abs(M(a, n, k + 1, a[k])))
    cm[i][w] = m
    return m

def M(a, n, i, w):
    if w in cM[i]: return cM[i][w]
    M = abs(a[n - 1] - w)
    for k in range(i, n - 1):
        M = max(M, abs(m(a, n, k + 1, a[k])))
    cM[i][w] = M
    return M

n, z, w = map(int, raw_input().split())
a = map(int, raw_input().split())
cm = [dict() for _ in range(n)]
cM = [dict() for _ in range(n)]
print M(a, n, 0, w)
