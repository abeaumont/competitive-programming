#!/usr/bin/env python
# https://www.codechef.com/APRIL21A/problems/CHAOSEMP/

LIMIT = 10**18


# with d = 0 we just do binary search
def solve0():
    x0 = y0 = -LIMIT
    x1 = y1 = LIMIT
    while True:
        x = (x0 + x1) // 2
        y = (y0 + y1) // 2
        print('1 {} {}'.format(x, y))
        ans = input()
        if ans == 'FAILED' or ans == 'O':
            return
        if ans[0] == 'N':
            x0 = x + 1
        elif ans[0] == 'P':
            x1 = x - 1
        else:
            x0 = x1 = x
        if ans[1] == 'N':
            y0 = y + 1
        elif ans[1] == 'P':
            y1 = y - 1
        else:
            y0 = y1 = y


# Solve when the previous position was identified.
# A ring of fire of size 2x2 around the position must hit the chip.
def solve1p(p):
    x, y = p
    print('2 {} {} {} {}'.format(x - 1, y - 1, x + 1, y + 1))
    input()


# Solve when the previous position was reduced to two options.
# So the actual positions are now 8.
# With a ring of fire of size 2x2 we can either hit the chip
# or uniquely identify its position and hit it with a second ring of fire.
def solve2p(p0, p1):
    x, y = p0
    print('2 {} {} {} {}'.format(x - 1, y - 1, x + 1, y + 1))
    ans = input()
    if ans == 'FAILED' or ans == 'O':
        return
    if ans == 'IN':
        solve1p((x, y))
    else:
        x0, y0 = p0
        x1, y1 = p1
        dx = x1 - x0
        dy = y1 - y0
        solve1p((x1 + dx, y1 + dy))


# Solve when the previous position was reduced to 4 options forming a 2x2 box.
# We can reduce this to 2 options with a ring of fire of size 3x2.
def solve4p(x0, y0, x1, y1):
    print('2 {} {} {} {}'.format(x0 - 1, y0 - 1, x1, y1 + 1))
    ans = input()
    if ans == 'FAILED' or ans == 'O':
        return
    if ans == 'IN':
        solve2p((x0, y0), (x0, y1))
    else:
        solve2p((x1 + 1, y0), (x1 + 1, y1))


# Solve a rectangle of size 5x5 or lower.
def solve5x5(x0, y0, x1, y1):
    x = (x0 + x1) // 2
    y = (y0 + y1) // 2
    print('1 {} {}'.format(x, y))
    ans = input()
    if ans == 'FAILED' or ans == 'O':
        return
    if ans[0] == 'N':
        x0 = x + 1
    elif ans[0] == 'P':
        x1 = x - 1
    else:
        x0 = x1 = x
    if ans[1] == 'N':
        y0 = y + 1
    elif ans[1] == 'P':
        y1 = y - 1
    else:
        y0 = y1 = y
    a = (x1 - x0 + 1) * (y1 - y0 + 1)
    if a == 1:
        solve1p((x0, y0))
    elif a == 2:
        solve2p((x0, y0), (x1, y1))
    else:
        solve4p(x0, y0, x1, y1)


# with d = 1 we do binary search, taking the account the possible movements,
# until the possible positions fit in a 5x5 rectangle,
# then we used specialized code.
def solve1():
    x0 = y0 = -LIMIT
    x1 = y1 = LIMIT
    while True:
        if x1 - x0 < 5 and y1 - y0 < 5:
            solve5x5(x0, y0, x1, y1)
            break
        x = (x0 + x1) // 2
        y = (y0 + y1) // 2
        print('1 {} {}'.format(x, y))
        ans = input()
        if ans == 'FAILED' or ans == 'O':
            return
        if ans[0] == 'N':
            x0 = x
            x1 += d
        elif ans[0] == 'P':
            x0 -= d
            x1 = x
        else:
            x0 = x - d
            x1 = x + d
        if ans[1] == 'N':
            y0 = y
            y1 += d
        elif ans[1] == 'P':
            y0 -= d
            y1 = y
        else:
            y0 = y - d
            y1 = y + d


t, q, d = map(int, input().split())
for _ in range(t):
    if d == 0:
        solve0()
    else:
        solve1()
