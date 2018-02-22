# https://open.kattis.com/problems/8queens
def check(board):
    r = set()
    c = set()
    d1 = set()
    d2 = set()
    for i in range(8):
        for j in range(8):
            if board[i][j] == '*':
                r.add(i)
                c.add(j)
                d1.add(i - j)
                d2.add(i + j)
    return len(r) == 8 and len(c) == 8 and len(d1) == 8 and len(d2) == 8

board = [raw_input() for i in range(8)]
print 'valid' if check(board) else 'invalid'
