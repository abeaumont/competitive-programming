#!/usr/bin/env pypy3
# Code taken from https://stackoverflow.com/questions/35259527/using-zlib-crc32-combine-in-python
import os


def crc32_combine(crc1, crc2, len2):
    """Explanation algorithm: https://stackoverflow.com/a/23126768/654160
    crc32(crc32(0, seq1, len1), seq2, len2) == crc32_combine(
        crc32(0, seq1, len1), crc32(0, seq2, len2), len2)"""
    # degenerate case (also disallow negative lengths)
    if len2 <= 0:
        return crc1

    # put operator for one zero bit in odd
    # CRC-32 polynomial, 1, 2, 4, 8, ..., 1073741824
    odd = [0xedb88320] + [1 << i for i in range(0, 31)]
    even = [0] * 32

    def matrix_times(matrix, vector):
        number_sum = 0
        matrix_index = 0
        while vector != 0:
            if vector & 1:
                number_sum ^= matrix[matrix_index]
            vector = vector >> 1 & 0x7FFFFFFF
            matrix_index += 1
        return number_sum

    # put operator for two zero bits in even - gf2_matrix_square(even, odd)
    even[:] = [matrix_times(odd, odd[n]) for n in range(0, 32)]

    # put operator for four zero bits in odd
    odd[:] = [matrix_times(even, even[n]) for n in range(0, 32)]

    # apply len2 zeros to crc1 (first square will put the operator for one
    # zero byte, eight zero bits, in even)
    while len2 != 0:
        # apply zeros operator for this bit of len2
        even[:] = [matrix_times(odd, odd[n]) for n in range(0, 32)]
        if len2 & 1:
            crc1 = matrix_times(even, crc1)
        len2 >>= 1

        # if no more bits set, then done
        if len2 == 0:
            break

        # another iteration of the loop with odd and even swapped
        odd[:] = [matrix_times(even, even[n]) for n in range(0, 32)]
        if len2 & 1:
            crc1 = matrix_times(odd, crc1)
        len2 >>= 1

        # if no more bits set, then done
    # return combined crc
    crc1 ^= crc2
    return crc1


def create_table():
    a = []
    for i in range(256):
        k = i
        for j in range(8):
            if k & 1:
                k ^= 0x1db710640
            k >>= 1
        a.append(k)
    return a


crc_table = create_table()

while True:
    try:
        f, n = input().split()
    except Exception:
        break
    n = int(n)
    xs = []
    sz = os.path.getsize(f'{os.getcwd()}/animals/{f}')
    crc = crc32_combine(0xffffffff, 0, sz) ^ 0xffffffff
    print(f'{f} 0: {hex(crc)[2:].zfill(8)}')
    for i in range(n):
        k, b = map(int, input().split())
        xs = [(l + 1 if k <= l else l, c) for l, c in xs]
        xs.append((k, b))
        sz += 1
        xs.sort()
        p = xs[0][0]
        crc = crc32_combine(0xffffffff, 0, p)
        for k, b in xs:
            crc = crc32_combine(crc, crc_table[b], k + 1 - p)
            p = k + 1
        crc = crc32_combine(crc, crc_table[0], sz - p)
        crc ^= 0xffffffff
        print(f'{f} {i+1}: {hex(crc)[2:].zfill(8)}')
