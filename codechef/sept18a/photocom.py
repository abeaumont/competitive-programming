#!/usr/bin/env pypy3
# https://www.codechef.com/SEPT18A/problems/PHOTOCOM
from math import gcd
import array

def f(s, h, w):
    m = [array.array('Q', [0]*w) for _ in range(h)]
    m[0][0] = int(s[0] == '1')
    for i in range(1, w):
        m[0][i] = m[0][i-1] + int(s[i] == '1')
    for i in range(1, h):
        c = 0
        for j in range(0, w):
            a = int(s[i*w+j] == '1')
            m[i][j] = c + m[i-1][j] + a
            c += a
    return m

def r(m,y1,y2,x1,x2):
    if y1==0 and x1==0: return m[y2][x2]
    if y1==0: return m[y2][x2]-m[y2][x1-1]
    if x1==0: return m[y2][x2]-m[y1-1][x2]
    return m[y2][x2]-m[y2][x1-1]-m[y1-1][x2]+m[y1-1][x1-1]

for _ in range(int(input())):
    h1, w1 = map(int, input().split())
    s1 = input()
    h2, w2 = map(int, input().split())
    s2 = input()
    if h1*w1 > h2*w2: h1,w1,s1,h2,w2,s2 = h2,w2,s2,h1,w1,s1
    p1 = [None]*h1
    for i in range(h1):
        p1[i] = [None]*w1
        for j in range(w1):
            p1[i][j] = s1[i*w1+j] == '1'
    p2 = [None]*h2
    for i in range(h2):
        p2[i] = [None]*w2
        for j in range(w2):
            p2[i][j] = s2[i*w2+j] == '1'
    m = f(s2, h2, w2)
    h = gcd(h1, h2)
    w = gcd(w1, w2)
    h = h1*h2//h
    w = w1*w2//w
    h1m, w1m = h//h1, w//w1
    h2m, w2m = h//h2, w//w2
    s = 0
    for i in range(h1):
        for j in range(w1):
            y1 = i*h1m
            y2 = (i+1)*h1m
            x1 = j*w1m
            x2 = (j+1)*w1m
            cy1 = (y1+h2m-1)//h2m
            cy2 = (y2+h2m-1)//h2m
            cx1 = (x1+w2m-1)//w2m
            cx2 = (x2+w2m-1)//w2m
            fy1 = y1//h2m
            fy2 = y2//h2m
            fx1 = x1//w2m
            fx2 = x2//w2m
            c0,c1,c2,c3,c4,c5,c6,c7,c8 = [0]*9
            if fy2 > cy1 and fx2 > cx1:
                k = r(m,cy1,fy2-1,cx1,fx2-1)
                a = (fy2-cy1)*(fx2-cx1)
                if p1[i][j]: c0 = k
                else: c0 = a-k
                c0 *= h2m*w2m
            # top and bottom
            if fy1 == fy2:
                if fx2 > cx1:
                    k = r(m,fy1,fy1,cx1,fx2-1)
                    a = fx2-cx1
                    if p1[i][j]: c1=k
                    else: c1=a-k
                    c1 *= (y2-y1)*w2m
            elif fx2 > cx1:    
                # top side
                if fy1 != cy1:
                    k = r(m,fy1,fy1,cx1,fx2-1)
                    a = fx2-cx1
                    if p1[i][j]: c1=k
                    else: c1=a-k
                    c1 *= w2m*(cy1*h2m-y1)
                # bottom side
                if fy2 != cy2:
                    k = r(m,fy2,fy2,cx1,fx2-1)
                    a = fx2-cx1
                    if p1[i][j]: c2=k
                    else: c2=a-k
                    c2 *= w2m*(y2-fy2*h2m)
            # left and right
            if fx1 == fx2:
                if fy2 > cy1:
                    k = r(m,cy1,fy2-1,fx1,fx1)
                    a = fy2-cy1
                    if p1[i][j]: c3=k
                    else: c3=a-k
                    c3 *= h2m*(x2-x1)
            elif fy2 > cy1:
                # left side
                if fx1 != cx1:
                    k = r(m,cy1,fy2-1,fx1,fx1)
                    a = fy2-cy1
                    if p1[i][j]: c3=k
                    else: c3=a-k
                    c3 *= h2m*(cx1*w2m-x1)
                # right side
                if fx2 != cx2:
                    k = r(m,cy1,fy2-1,fx2,fx2)
                    a = fy2-cy1
                    if p1[i][j]: c4=k
                    else: c4=a-k
                    c4 *= h2m*(x2-fx2*w2m)
            if fx1 == fx2 and fy1 == fy2:
                if fx1 != cx2 and fy1 != cy2:
                    if p2[fy1][fx1] == p1[i][j]: c5 += (x2-x1)*(y2-y1)
            elif fx1 == fx2:
                # tl and tr
                if fx1 != cx2 and fy1 != cy1:
                    if p2[fy1][fx1] == p1[i][j]: c5 += (x2-x1)*(cy1*h2m-y1)
                # bl and br
                if fx1 != cx2 and fy2 != cy2:
                    if p2[fy2][fx2] == p1[i][j]: c7 += (x2-x1)*(y2-fy2*h2m)
            elif fy1 == fy2:
                # tl and bl
                if fx1 != cx1 and fy1 != cy2:
                    if p2[fy1][fx1] == p1[i][j]: c5 += (cx1*w2m-x1)*(y2-y1)
                # tr and br
                if fx2 != cx2 and fy1 != cy2:
                    if p2[fy1][fx2] == p1[i][j]: c6 += (x2-fx2*w2m)*(y2-y1)
            else:
                # tl
                if fx1 != cx1 and fy1 != cy1:
                    if p2[fy1][fx1] == p1[i][j]: c5 += (cx1*w2m-x1)*(cy1*h2m-y1)
                # tr
                if fx2 != cx2 and fy1 != cy1:
                    if p2[fy1][fx2] == p1[i][j]: c6 += (x2-fx2*w2m)*(cy1*h2m-y1)
                # br
                if fx2 != cx2 and fy2 != cy2:
                    if p2[fy2][fx2] == p1[i][j]: c7 += (x2-fx2*w2m)*(y2-fy2*h2m)
                # bl
                if fx1 != cx1 and fy2 != cy2:
                    if p2[fy2][fx1] == p1[i][j]: c8 += (cx1*w2m-x1)*(y2-fy2*h2m)
            s += c0+c1+c2+c3+c4+c5+c6+c7+c8
    print(s)
