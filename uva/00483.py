#!/usr/bin/env python3
# https://uva.onlinejudge.org/external/4/483.pdf
while True:
    try:
        l=input()
        print(' '.join([x[::-1] for x in l.split()]))
    except:break
