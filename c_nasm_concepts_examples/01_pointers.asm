; Example: Pass-by-pointer in x64 NASM Assembly
; ---------------------------------------------
; This program demonstrates passing a pointer to a function (subroutine)
; and modifying the value at that address, just like in the C example.
;
; C equivalent:
; void set_to_100(int *ptr) { *ptr = 100; }
; int x = 42;
; set_to_100(&x);
; printf("x = %d\n", x);

section .data
    fmt db "x = %d", 10, 0

section .bss
    x resd 1

section .text
    extern printf
    global main

main:
    mov dword [x], 42         ; x = 42
    lea rdi, [x]              ; rdi = &x (pointer to x)
    call set_to_100           ; set_to_100(&x)
    mov eax, [x]              ; eax = x
    mov rdi, fmt              ; 1st arg: format string
    mov esi, eax              ; 2nd arg: x
    xor eax, eax              ; rax = 0 for printf
    call printf               ; printf("x = %d\n", x)
    mov eax, 0
    ret

; void set_to_100(int *ptr) { *ptr = 100; }
set_to_100:
    mov dword [rdi], 100      ; *ptr = 100
    ret
