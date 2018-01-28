# https://open.kattis.com/problems/different
while True:
    try:
        [a, b] = map(int, raw_input().split())
        print abs(a - b)
    except:
        break
