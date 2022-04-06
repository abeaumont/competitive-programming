#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b
for t in range(int(input())):
    r, c = map(int, input().split())
    print(f'Case #{t+1}:')
    for i in range(r):
        if i == 0:
            print('..' + '+-' * (c-1) + '+')
            print('..' + '|.' * (c-1) + '|')
        else:
            print('+-' * c + '+')
            print('|.' * c + '|')
    print('+-' * c + '+')
