import sys
import struct

class Array(object):
    def __init__(self, size=None, code=None):
        self.code = [0] * size if code is None else code
        self.pc = 0

    def instruction(self):
        ins = self.code[self.pc]
        self.pc += 1
        return ins

    def load(self, offset):
        return self.code[offset]

    def store(self, offset, data):
        self.code[offset] = data

def run(code):
    arrays = [Array(code=[struct.unpack('>I', code[i * 4:(i + 1) * 4])[0]
                          for i in range(len(code) / 4)])]
    regs = [0] * 8
    while True:
        i = arrays[0].instruction()
        op = i >> 28
        a = (i >> 6) & 0x7
        b = (i >> 3) & 0x7
        c = i & 0x7
        if op == 0:
            if regs[c] != 0:
                regs[a] = regs[b]
        elif op == 1:
            regs[a] = arrays[regs[b]].load(regs[c])
        elif op == 2:
            arrays[regs[a]].store(regs[b], regs[c])
        elif op == 3:
            regs[a] = (regs[b] + regs[c]) % (2 ** 32)
        elif op == 4:
            regs[a] = (regs[b] * regs[c]) % (2 ** 32)
        elif op == 5:
            regs[a] = regs[b] // regs[c]
        elif op == 6:
            regs[a] = ~(regs[b] & regs[c]) & 0xffffffff
        elif op == 7:
            break
        elif op == 8:
            idx = len(arrays)
            array = Array(size=regs[c])
            arrays.append(array)
            regs[b] = idx
        elif op == 9:
            if regs[c] == 0:
                raise Exception('trying to abandon address 0')
            if arrays[regs[c]] is None:
                raise Exception('already abandoned')
            arrays[regs[c]] = None
        elif op == 10:
            if regs[c] > 255:
                raise Exception('value to output not between 0 and 255: {}'.format(regs[c]))
            sys.stdout.write(chr(regs[c]))
        elif op == 11:
            try:
                reg[c] = sys.stdin.read(1)
            except:
                reg[c] = 0xffffffff
        elif op == 12:
            if regs[b] == 0:
                arrays[0].pc = regs[c]
                continue
            arrays[0] = Array(code=arrays[regs[b]].code[:])
            arrays[0].pc = regs[c]
        elif op == 13:
            op = i >> 28
            a = (i >> 25) & 0x7
            v = i & 0x1ffffff
            regs[a] = v
        else:
            raise Exception('invalid operation: {}'.format(op))


if __name__ == '__main__':
    run(open(sys.argv[1], 'rb').read())
