# https://www.hackerrank.com/challenges/nested-list
m1, m2 = None, None
s = []
for _ in range(input()):
    a = raw_input()
    b = input()
    s.append((a, b))
    if m1 is None:
        m1 = b
    elif b < m1:
        m2 = m1
        m1 = b
    elif b != m1 and (m2 is None or b < m2):
        m2 = b
for name in sorted([a for a, b in s if b == m2]):
    print name
