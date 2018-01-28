# https://open.kattis.com/problems/mandelbrot
import math

case = 0
while True:
    case += 1
    try:
        fields = raw_input().split()
        [x, y, n] = fields
        cx = float(x)
        cy = float(y)
        n = int(n)
        zx, zy = 0, 0
        result = 'IN'
        for i in xrange(n):
            t = zx * zx - zy * zy + cx
            zy = 2 * zx * zy + cy
            zx = t
            r = math.sqrt(zx * zx + zy * zy)
            if math.isnan(r) or r > 2:
                result = 'OUT'
                break
        print 'Case {}: {}'.format(case, result)
    except:
        break
