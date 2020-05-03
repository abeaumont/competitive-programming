#!/usr/bin/env pypy3

LB = 0
RB = 1
COMMA = 2
NC = 3
NL = 4

INF = 10000


def prep(ls):
    code = []
    for l in ls:
        for c in l:
            if c == '[':
                code.append(LB)
            elif c == ']':
                code.append(RB)
            elif c == ',':
                code.append(COMMA)
            else:
                code.append(NC)
        code.append(NL)
    code.pop()
    return code


def lolmao(ls):
    code = prep(ls)
    l = len(code)
    # dp is index x depth x symbol x comma
    dp = [None] * l
    for i in range(l):
        dp[i] = [None] * (l+1)
        for j in range(l+1):
            dp[i][j] = [None] * 5
            for k in range(5):
                dp[i][j][k] = [INF] * 2
    # setup initial status
    dp[0][1][LB][0] = 0 if code[0] == LB else 1
    alls = [LB, RB, COMMA, NC, NL]
    ncs = [LB, COMMA, NC, NL]
    lbs = [LB, COMMA]
    for i in range(1, l-1):
        c = code[i]
        for j in range(l):
            if c == NL:
                # We cannot keep it if we don't have a comma
                for s in ncs:
                    dp[i][j][NL][0] = min(dp[i][j][NL][0], dp[i-1][j][s][1])
                # We can also move it to a comma
                for s in alls:
                    for k in range(2):
                        dp[i][j][COMMA][1] = min(dp[i][j][COMMA][1], dp[i-1][j][s][k] + 1)
                # We can move to other symbols
                for s in ncs:
                    for k in range(2):
                        dp[i][j][NC][k] = min(dp[i][j][NC][k], dp[i-1][j][s][k] + 1)
                if j > 1:
                    for s in alls:
                        for k in range(2):
                            dp[i][j-1][RB][k] = min(dp[i][j-1][RB][k], dp[i-1][j][s][k] + 1)
                for s in lbs:
                    for k in range(2):
                        dp[i][j+1][LB][k] = min(dp[i][j+1][LB][k], dp[i-1][j][s][k] + 1)
            else:
                costs = [1] * 5
                costs[c] = 0
                # We can always include a left bracket, since depth won't overflow.
                for s in lbs:
                    for k in range(2):
                        dp[i][j+1][LB][k] = min(dp[i][j+1][LB][k], dp[i-1][j][s][k] + costs[0])
                # Or a RB if j > 0
                if j > 1:
                    for s in alls:
                        for k in range(2):
                            dp[i][j-1][RB][k] = min(dp[i][j-1][RB][k], dp[i-1][j][s][k] + costs[1])
                # We can move to a comma
                for s in alls:
                    for k in range(2):
                        dp[i][j][COMMA][1] = min(dp[i][j][COMMA][1], dp[i-1][j][s][k] + costs[2])
                # We can also move to a NC
                for s in ncs:
                    for k in range(2):
                        dp[i][j][NC][k] = min(dp[i][j][NC][k], dp[i-1][j][s][k] + costs[3])
                # We can move to a NL if we already had a comma
                for s in ncs:
                    dp[i][j][NL][0] = min(dp[i][j][NL][0], dp[i-1][j][s][1] + costs[4])
    cost = min(dp[l-2][1][s][1] for s in alls) + (1 if code[-1] != RB else 0)
    if cost >= INF:
        return "IMPOSSIBLE"
    return cost


for t in range(int(input())):
    l = int(input())
    ls = [None] * l
    for i in range(l):
        ls[i] = input()
    print(f'Case #{t+1}: {lolmao(ls)}')
