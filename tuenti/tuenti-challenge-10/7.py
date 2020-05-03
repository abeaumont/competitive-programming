#!/usr/bin/env python
qwerty = "-=qwertyuiop[]asdfghjkl;'zxcvbnm,./_+QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?"
dvorak = "[]',.pyfgcrl/=aoeuidhtns-;qjkxbmwvz{}\"<>PYFGCRL?+AOEUIDHTNS_:QJKXBMWVZ"
t = str.maketrans(dvorak, qwerty)
for i in range(int(input())):
    print(f'Case #{i+1}: {input().translate(t)}')
