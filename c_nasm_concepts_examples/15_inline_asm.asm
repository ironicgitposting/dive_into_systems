
; Example 15: Inline assembly in x64 NASM Assembly
; -----------------------------------------------
; In assembly, all code is 'inline'. This example adds two numbers and prints the result.
; 
; MEMORY & REGISTER OVERVIEW:
; - eax, ebx: Used for int values (like int a, b in C)
; - add: Adds two values (like a + b)
; - esi: Used for printf argument
; - edi: 1st function argument (format string)
; 
; C EQUIVALENT:
; int a = 5, b = 3;
; int result = a + b;
; printf("result = %d\n", result);
; 
; Run with: nasm -f elf64 15_inline_asm.asm && gcc -no-pie -o 15_inline_asm 15_inline_asm.o && ./15_inline_asm


section .data
    fmt db "result = %d", 10, 0      ; Format string


section .text
    extern printf
    global main


main:
    ; Set a = 5, b = 3 (like: int a = 5, b = 3;)
    mov eax, 5          ; eax = a = 5
    mov ebx, 3          ; ebx = b = 3
    add eax, ebx        ; eax = a + b
    mov esi, eax        ; 2nd arg: result
    mov edi, fmt        ; 1st arg: format string
    xor eax, eax        ; rax = 0 for printf
    call printf         ; printf("result = %d\n", result);
    mov eax, 0
    ret
