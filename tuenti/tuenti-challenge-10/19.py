#!/usr/bin/env python3
import os
import hashlib
d = dict()
e = 5 # 2
for i in range(10**e):
    fn = f'/mnt/cow{str(i).zfill(e)}'
    l = os.path.getsize(fn)
    with open(fn, 'rb') as f:
        offset = f.seek(0, 3)
        for i in range(offset, l):
            if f.read(1) != b'\x00':
                d[i] = d.get(i, [])
                d[i].append(fn)
                break


fn = None
for k, v in d.items():
    if len(v) == 1:
        fn = v[0]

sha256 = hashlib.sha256()
with open(fn, 'rb') as f:
    while True:
        data = f.read(2**16)
        if not data:
            break
        sha256.update(data)

print(f'Case #1: {sha256.hexdigest()}')
