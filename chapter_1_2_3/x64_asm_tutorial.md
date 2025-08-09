# x64 Assembly Language Tutorial

This tutorial introduces the basics of x86-64 (x64) assembly language, focusing on Linux systems and the NASM/GAS syntax. It is designed for C/C++ programmers who want to understand how high-level code maps to machine instructions.

---

## 1. Registers
- 16 general-purpose 64-bit registers: `rax`, `rbx`, `rcx`, `rdx`, `rsi`, `rdi`, `rbp`, `rsp`, `r8`-`r15`
- Lower 32/16/8 bits: `eax`/`ax`/`al` (for `rax`), etc.
- Special registers:
  - `rsp`: stack pointer
  - `rbp`: base/frame pointer
  - `rip`: instruction pointer

## 2. Data Movement
```asm
mov rax, 5        ; rax = 5
mov rbx, rax      ; rbx = rax
mov [rbx], rax    ; store rax at address in rbx
```

## 3. Arithmetic
```asm
add rax, rbx      ; rax += rbx
sub rax, 10       ; rax -= 10
imul rax, 2       ; rax *= 2
```

## 4. Stack Operations
```asm
push rax          ; push rax onto stack
pop rbx           ; pop top of stack into rbx
```

## 5. Function Calls (System V ABI)
- First 6 integer/pointer args: `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`
- Return value: `rax`
- Caller saves: `r10`, `r11`, `rax`, `rcx`, `rdx`, `rsi`, `rdi`, `r8`, `r9`
- Callee saves: `rbx`, `rbp`, `r12`-`r15`

## 6. Control Flow
```asm
cmp rax, rbx      ; compare rax and rbx
je label          ; jump if equal
jne label         ; jump if not equal
jmp label         ; unconditional jump
```

## 7. Example: Hello World (NASM, Linux)
```asm
section .data
    msg db "Hello, world!", 0xA
    len equ $-msg
section .text
    global _start
_start:
    mov rax, 1          ; syscall: write
    mov rdi, 1          ; file descriptor: stdout
    mov rsi, msg        ; pointer to message
    mov rdx, len        ; message length
    syscall             ; invoke kernel
    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; status 0
    syscall
```

## 8. Example: Simple Addition Function
```asm
; int add(int a, int b) { return a + b; }
global add
add:
    mov rax, rdi    ; first argument (a) in rdi
    add rax, rsi    ; second argument (b) in rsi
    ret
```

## 9. Assembling and Running (NASM)
```sh
nasm -f elf64 hello.asm -o hello.o
ld hello.o -o hello
./hello
```

## 10. Useful Tips
- Comments start with `;` (NASM) or `#` (GAS)
- Use `man syscall` for Linux syscall numbers
- Use `objdump -d` to disassemble binaries

---

## References
- [x86-64 Instruction Set Reference](https://www.felixcloutier.com/x86/)
- [NASM Documentation](https://www.nasm.us/doc/)
- [System V AMD64 ABI](https://refspecs.linuxbase.org/LSB_3.0.0/LSB-PDA/LSB-PDA/specialsections/amd64/)
