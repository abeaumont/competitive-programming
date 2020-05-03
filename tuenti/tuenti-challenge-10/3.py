#!/usr/bin/env python3
with open('pg17013.txt') as f:
    contents = f.read().lower()
alphabet = 'abcdefghijklmnñopqrstuvwxyzáéíóúü'
contents = ''.join(x if x in alphabet else ' ' for x in contents)
words = {}
for w in contents.split():
    if len(w) < 3: continue
    words[w] = words.get(w, 0) + 1
words = sorted([(-v, k) for k, v in words.items()])
indices = {}
for i, w in enumerate(words):
    indices[w[1]] = (-w[0], i)
for t in range(int(input())):
    k = input()
    if ord(k[0]) >= 0x30 and ord(k[0]) <= 0x39:
        k = int(k)-1
        k, w = words[k]
        print(f'Case #{t+1}: {w} {-k}')
    else:
        w, i = indices[k]
        print(f'Case #{t+1}: {w} #{i+1}')
