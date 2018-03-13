# https://abc080.contest.atcoder.jp/tasks/abc080_c
import itertools

n = input()
f = []
for _ in range(n):
    f.append(map(int, raw_input().split()))
p = []
for _ in range(n):
    p.append(map(int, raw_input().split()))

best = -100000000000
for i in range(1, 11):
    for x in itertools.combinations(range(0, 10), i):
        sum = 0
        for j in range(n):
            fs = 0
            for k in x:
                if f[j][k] == 1: fs += 1
            sum += p[j][fs]
        if sum > best:
            best = sum
print best
