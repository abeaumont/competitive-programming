# https://open.kattis.com/problems/pathtracing
import sys

x = 0
y = 0
min_x, max_x = x, x
min_y, max_y = y, y
seq = [(0, 0)]
while True:
    try:
        line = raw_input()
        if line == 'down':
            y -= 1
        elif line == 'up':
            y += 1
        elif line == 'left':
            x -= 1
        elif line == 'right':
            x += 1
        else:
            print >> sys.stderr, line
            continue
        min_x = min(x, min_x)
        max_x = max(x, max_x)
        min_y = min(y, min_y)
        max_y = max(y, max_y)
        seq.append((x, y))
    except :
        break

seq = [(x - min_x, max_y - y) for (x, y) in seq]
max_x -= min_x
max_y -= min_y
print '#' * (max_x + 3)
for y in range(max_y + 1):
    sys.stdout.write('#')
    for x in range(max_x + 1):
        if (x, y) == seq[0]:
            sys.stdout.write('S')
        elif (x, y) == seq[-1]:
            sys.stdout.write('E')
        elif (x, y) in seq:
            sys.stdout.write('*')
        else:
            sys.stdout.write(' ')
    sys.stdout.write('#\n')
print '#' * (max_x + 3)
