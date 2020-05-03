#!/usr/bin/env python
import binascii
c = binascii.unhexlify('3633363A33353B393038383C363236333635313A353336')
p = '514;248;980;347;145;332'
k = [ord(x) ^ y for x, y in zip(p, c)]
c = binascii.unhexlify('3A3A333A333137393D39313C3C3634333431353A37363D')
print(''.join(chr(x ^ y) for x, y in zip(c, k)))
