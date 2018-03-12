# https://abc088.contest.atcoder.jp/tasks/abc088_b
n = input()
a = map(int, raw_input().split())
a.sort(reverse=True)
s1 = 0
s2 = 0
for i, k in enumerate(a):
    if i % 2 == 0:
        s1 += k
    else:
        s2 += k
print s1 - s2
