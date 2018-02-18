def f(c):
    for a1 in range(101):
        for a2 in range(101):
            for a3 in range(101):
                b1 = c[0][0] - a1
                b2 = c[0][1] - a1
                b3 = c[0][2] - a1
                if b1 == c[1][0] - a2 and b1 == c[2][0] - a3 and \
                   b2 == c[1][1] - a2 and b2 == c[2][1] - a3 and \
                   b3 == c[1][2] - a2 and b3 == c[2][2] - a3:
                    return True
    return False
                
c = [map(int, raw_input().split()) for _ in range(3)]
if f(c): print 'Yes'
else: print 'No'
