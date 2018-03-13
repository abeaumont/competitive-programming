# https://abc042.contest.atcoder.jp/tasks/arc058_a
[n, k] = map(int, raw_input().split())
d = raw_input().split()
while True:
    ok = True
    for c in str(n):
        if c in d:
            ok = False
            break
    if ok:
        print n
        break
    n += 1
