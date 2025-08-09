
; Example 11: Casting and type conversions in x64 NASM Assembly
; ------------------------------------------------------------
; Demonstrates converting a double to int (truncation) and printing both.
; 
; MEMORY & REGISTER OVERVIEW:
; - xmm0: Used for double value (like double d in C)
; - esi: Used for int value (like int i in C)
; - rdi: 1st function argument (format string)
; - cvttsd2si: Convert double in xmm0 to int in esi (truncate)
; 
; C EQUIVALENT:
; double d = 3.7;
; int i = (int)d;
; printf("d = %f, i = %d\n", d, i);
; 
; Run with: nasm -f elf64 11_casting.asm && gcc -no-pie -o 11_casting 11_casting.o && ./11_casting


section .data
    fmt db "d = %f, i = %d", 10, 0      ; Format string


section .text
    extern printf
    global main


main:
    ; Set d = 3.7 (like: double d = 3.7;)
    mov rdi, fmt            ; 1st arg: format string
    movq xmm0, __float64__(3.7) ; xmm0 = d = 3.7
    cvttsd2si esi, xmm0     ; esi = (int)d (truncate)
    xor eax, eax            ; rax = 0 for printf
    call printf             ; printf("d = %f, i = %d\n", d, i);
    mov eax, 0
    ret
