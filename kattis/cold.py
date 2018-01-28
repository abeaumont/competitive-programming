# https://open.kattis.com/problems/cold
input()
print(len(filter(lambda x: x < 0, map(int, raw_input().split()))))
