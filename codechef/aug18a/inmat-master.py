#!/usr/bin/env python3
import sys
from subprocess import Popen, PIPE

with Popen(['./inmat-gen.py', sys.argv[1]], stdin=PIPE, stdout=PIPE, bufsize=1, universal_newlines=True) as p:
    with Popen(['./a.out'], stdin=PIPE, stdout=PIPE, bufsize=1, universal_newlines=True) as q:
        while True:
            line = p.stdout.readline()
            sys.stdout.write(line)
            if line[0] in 'FO':
                if line[0] == 'O': break
                sys.exit(1)
            q.stdin.write(line)
            line = q.stdout.readline()
            sys.stdout.write(line)
            p.stdin.write(line)
