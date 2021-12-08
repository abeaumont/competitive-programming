;; nasm part1.asm -f elf64 && ld -o part1 part1.o
section .data
births: times 100 dd 0
count: dd 0
buf: dd 0

section .text
global _start

_start:
  call readinput
  xor rcx, rcx
init:
  movsxd rax, [births+4*rcx]
  mov [births+4*(rcx+7)], eax
  inc rcx
  cmp rcx, 80
  jne init
  xor rcx, rcx
outer:
  movsxd rax, [births+4*rcx]
  add [count], rax
  test rax, rax
  jz out
  mov rbx, rcx
  add rbx, 9
inner:
  cmp rbx, 80
  jge out
  add [births+4*rbx], eax
  add rbx, 7
  jmp inner
out:
  inc rcx
  cmp rcx, 80
  jne outer
  mov rax, count
  call print
  mov dword [buf], 0xa
  call write
  xor rdi, rdi
  mov rax, 0x3c
  syscall

readinput:
  xor rdi, rdi
  lea rsi, buf
  mov rdx, 0x1
read:
  xor rax, rax
  syscall
  mov rax, [buf]
  cmp rax, 0xa
  je eof
  cmp rax, 0x2c
  je read
  inc dword [births+4*(rax-0x30)]
  inc dword [count]
  jmp read
eof:
  ret

print:
  movsxd rbx, [rax]
  mov rax, rbx
  test rax, rax
  jnz digits
  mov dword [buf], 0x30
  call write
  ret
digits:  
  mov rbx, 0x3b9aca00
loop0:
  xor rdx, rdx
  div rbx
  mov r8, rax
  mov r9, rdx
  mov rax, rbx
  xor rdx, rdx
  mov rbx, 10
  div rbx
  mov rbx, rax
  mov rax, r9
  test r8, r8
  jz loop0
loop1:
  mov [buf], r8
  add dword [buf], 0x30
  call write
  test rbx, rbx
  jz end
  xor rdx, rdx
  mov rax, r9
  div rbx
  mov r8, rax
  mov r9, rdx
  mov rax, rbx
  xor rdx, rdx
  mov rbx, 10
  div rbx
  mov rbx, rax
  mov rax, r9
  jmp loop1
end:
  ret
  
write:
  mov rdi, 0x1
  lea rsi, [buf]
  mov rdx, 0x1
  mov rax, 0x1
  syscall
  ret
