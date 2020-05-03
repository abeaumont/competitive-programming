#!/usr/bin/env python3
import re
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('52.49.91.111', 2092))
r = s.makefile(mode='rw')
c = 0
sid = None
while c < 2:
    l = r.readline()
    print(l, end='')
    if sid is None:
        sid = int(l.split()[2])
        if sid != 9:
            break
    if l[0] == '#':
        c += 1
print(r.readline(), end='')

p = re.compile(r'ROUND (\d+): (\d+) -> (\w+) (.*)')
paccepted = re.compile(r'{servers: (\[.*\]), secret_owner: (\d+)}')
ppromise = re.compile(r'{(\d+),\d+}.*')

servers = set()
secret_owner = None
counter = dict()
owners = dict()
promises = dict()
promisers = dict()

owned = list(range(9, 16))
while True:
    l = r.readline()
    print(l, end='')
    if l.startswith('SECRET'):
        break
    m = p.match(l)
    if m is None:
        continue
    if m.group(3) == 'ACCEPTED':
        m2 = paccepted.match(m.group(4))
        secret_owner = m2.group(2)
        ls = owners.get(m.group(1), [])
        ls.append(m.group(2))
        owners[m.group(1)] = ls
        counter[m.group(1)] = counter.get(m.group(1), 0) + 1
        servers = set(eval(m2.group(1)) + [int(m.group(2))])
        if counter[m.group(1)] * 2 > len(servers) or len(servers) <= 3:
            for o in owners[m.group(1)]:
                s = f'PREPARE {{{int(m.group(1))+1},{sid}}} -> {o}'
                print(s)
                r.write(s+'\n')
                r.flush()
    if m.group(3) == 'PROMISE':
        m2 = ppromise.match(m.group(4))
        id = m2.group(1)
        ls = promisers.get(id, [])
        ls.append(m.group(2))
        promisers[id] = ls
        promises[id] = promises.get(id, 0) + 1
        if promises[id] * 2 >= len(servers):
            so = int(secret_owner)
            ss = servers
            added = False
            for q in owned:
                if q not in ss:
                    ss.add(q)
                    added = True
                    break
            if not added:
                if len(servers) <= 10:
                    so = 9
                else:
                    ss = servers
                    q = ss.pop()
                    while q in owned or so == q:
                        ss.add(q)
            ss = f'{list(ss)}'.replace(' ', '')
            for o in promisers[id]:
                s = f'ACCEPT {{id: {{{id},{sid}}}, value: {{servers: {ss}, secret_owner: {so}}}}} -> {o}'
                print(s)
                r.write(s+'\n')
                r.flush()
