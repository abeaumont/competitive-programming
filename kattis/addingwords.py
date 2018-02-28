# https://open.kattis.com/problems/addingwords
a = {}
b = {}
while True:
    try:
        line = raw_input()
    except:
        break
    fs = line.split()
    if fs[0] == 'def':
        n = fs[1]
        v = int(fs[2])
        if n in a: del(b[a[n]])
        a[n] = v
        b[v] = n
    elif fs[0] == 'calc':
        r = 0
        result = True
        if fs[1] not in a: result = False
        else: r = a[fs[1]]
        for i in range(2, len(fs), 2):
            if fs[i] == '=': break
            plus = fs[i] == '+'
            if fs[i + 1] not in a: result = False
            elif plus: r += a[fs[i + 1]]
            else: r -= a[fs[i + 1]]
        print ' '.join(fs[1:]),
        if not result or r not in b: print 'unknown'
        else: print b[r]
    elif fs[0] == 'clear':
        a = {}
        b = {}
