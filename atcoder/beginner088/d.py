# https://abc088.contest.atcoder.jp/tasks/abc088_d
import sys
import Queue

sys.setrecursionlimit(1000000)

def s(m, v, q):
    if q.empty(): return -1
    k, i, j = q.get()
    if i == len(m) - 1 and j == len(m[i]) - 1: return k
    if i > 0 and m[i - 1][j] == '.' and (i - 1, j) not in v:
        q.put((k + 1, i - 1, j))
        v.add((i - 1, j))
    if i < len(m) - 1 and m[i + 1][j] == '.' and (i + 1, j) not in v:
        q.put((k + 1, i + 1, j))
        v.add((i + 1, j))
    if j > 0 and m[i][j - 1] == '.' and (i, j - 1) not in v:
        q.put((k + 1, i, j - 1))
        v.add((i, j - 1))
    if j < len(m[i]) - 1 and m[i][j + 1] == '.' and (i, j + 1) not in v:
        q.put((k + 1, i, j + 1))
        v.add((i, j + 1))
    return s(m, v, q)
     
h, w = map(int, raw_input().split())
m = [raw_input() for _ in range(h)]
q = Queue.PriorityQueue()
q.put((1, 0, 0))
v = set((0, 0))
c = s(m, v, q)
if c == -1: print -1
else: print h * w - c - sum([r.count('#') for r in m])
