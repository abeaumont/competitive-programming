# https://abc080.contest.atcoder.jp/tasks/abc080_d
[n, c] = map(int, raw_input().split())
cs = [None] * c
for i in range(c):
    cs[i] = list()
for i in range(n):
    [s, t, ci] = map(int, raw_input().split())
    cs[ci - 1].append((s, t))
starts = []
ends = []
for i in range(c):
    if len(cs[i]) == 0: continue
    cs[i].sort()
    j = 0
    k = 0
    while j + k < len(cs[i]) - 1:
        a = cs[i][j+k][1]
        b = cs[i][j+k+1][0]
        if a == b:
            k += 1
        else:
            start = cs[i][j][0]
            end = cs[i][j+k][1]
            starts.append(start)
            ends.append(end)
            j += k + 1
            k = 0
    start = cs[i][j][0]
    end = cs[i][j+k][1]
    starts.append(start)
    ends.append(end)
starts.sort()
ends.sort()
i = 0
j = 0
d = 0
while i < len(starts) and j < len(ends):
    if starts[i] < ends[j]:
        i += 1
    elif starts[i] == ends[j]:
        i += 1
    else:
        j += 1
    d = max(d, i - j)
print d
