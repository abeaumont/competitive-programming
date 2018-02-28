# https://open.kattis.com/problems/virtualfriends
def find(l, x):
    while x != l[x]: x = l[x]
    return x

def unite(l, s, a, b):
    a = find(l, a)
    b = find(l, b)
    if a == b: return
    if s[a] < s[b]: a, b = b, a
    s[a] += s[b]
    l[b] = a

for _ in range(input()):
    n = input()
    l = range(2 * n)
    s = [1] * 2 * n
    c = 0
    m = {}
    for _ in range(n):
        s1, s2 = raw_input().split()
        a = m.get(s1, c)
        if a == c:
            m[s1] = c
            c += 1
        b = m.get(s2, c)
        if b == c:
            m[s2] = c
            c += 1
        unite(l, s, a, b)
        print s[find(l, a)]
