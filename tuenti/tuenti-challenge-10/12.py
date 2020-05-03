#!/usr/bin/env python3
import binascii
import math

with open('plaintexts/test1.txt', 'rb') as f:
    pt1 = int(binascii.hexlify(f.read()), 16)
with open('plaintexts/test2.txt', 'rb') as f:
    pt2 = int(binascii.hexlify(f.read()), 16)
with open('ciphered/test1.txt', 'rb') as f:
    ct1 = int(binascii.hexlify(f.read()), 16)
with open('ciphered/test2.txt', 'rb') as f:
    ct2 = int(binascii.hexlify(f.read()), 16)

e = 65537
print(math.gcd(pow(pt1, e) - ct1, pow(pt2, e) - ct2))
