#!/usr/bin/env python3
# https://codeforces.com/contest/798/problem/A
word = input().strip()
i = 0
j = len(word) - 1
count = 0
while i <= j:
    if word[i] != word[j]:
        count +=1
    i += 1
    j -= 1
if count == 1 or count == 0 and len(word) % 2 == 1:
    print("YES")
else:
    print("NO")
