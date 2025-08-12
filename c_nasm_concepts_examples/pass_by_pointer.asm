; pass_by_pointer.asm
; Demonstrates pass-by-pointer: function modifies a variable and returns its old value
; C equivalent:
; int change_value(int *input) {
;     int old = *input;
;     *input = 100;
;     return old;
; }
; int x = 30;
; int y = change_value(&x);
; printf("x: %d y: %d\n", x, y); // prints x: 100 y: 30

section .data
    fmt db "x: %d y: %d", 10, 0

section .bss
    x resd 1
    y resd 1

section .text
    extern printf
    global main

main:
    mov dword [x], 30         ; x = 30
    lea rdi, [x]              ; rdi = &x (pointer to x)
    call change_value         ; y = change_value(&x)
    mov [y], eax              ; store return value in y
    mov eax, [x]              ; eax = x
    mov esi, [y]              ; esi = y
    mov rdi, fmt              ; rdi = format string
    xor eax, eax              ; rax = 0 for printf
    call printf               ; printf("x: %d y: %d\n", x, y)
    mov eax, 0
    ret

; int change_value(int *input) { int old = *input; *input = 100; return old; }
change_value:
    mov eax, [rdi]            ; eax = *input (old value)
    mov dword [rdi], 100      ; *input = 100
    ret
