# https://open.kattis.com/problems/cross
def cross(sudoku, n):
    rows = {x for x in range(9)}
    cols = {x for x in range(9)}
    squares = {x for x in range(9)}
    for i in range(9):
        for j in range(9):
            if sudoku[i][j] == n:
                rows.discard(i)
                cols.discard(j)
                squares.discard((i // 3) * 3 + j // 3)
    if len(rows) == 0: return None
    for s in squares:
        srows = {x for x in range((s // 3) * 3, (s // 3 + 1) * 3) if x in rows}
        scols = {x for x in range((s % 3) * 3, (s % 3 + 1) * 3) if x in cols}
        if len(srows) == 0 or len(scols) == 0: raise Exception()
        pos = [(y, x) for y in srows for x in scols if sudoku[y][x] == '.']
        if len(pos) == 0:
            raise Exception()
        if len(pos) == 1:
            return pos[0]
    return None

sudoku = [map(lambda x: x, raw_input()) for i in range(9)]
while True:
    end = True
    error = False
    for n in range(1, 10):
        try:
            ret = cross(sudoku, str(n))
            if ret is not None:
                end = False
                y, x = ret
                sudoku[y][x] = str(n)
        except Exception as e:
            error = True
            break
    if end:
        if error:
            print 'ERROR'
        else:
            print '\n'.join(map(lambda x: ''.join(x), sudoku))
        break
