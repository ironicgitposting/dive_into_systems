
; Example 9: Function declaration, prototype, and scope in x64 NASM Assembly
; -------------------------------------------------------------------------
; Demonstrates a simple function (add) and calling it from main.
; 
; MEMORY & REGISTER OVERVIEW:
; - edi, esi: Used for function arguments (int a, int b)
; - eax: Used for return value (int)
; - call: Calls a function (like calling add(a, b) in C)
; - ret: Returns from function
; 
; C EQUIVALENT:
; int add(int a, int b) { return a + b; }
; int sum = add(2, 3);
; printf("sum = %d\n", sum);
; 
; Run with: nasm -f elf64 09_functions_scope.asm && gcc -no-pie -o 09_functions_scope 09_functions_scope.o && ./09_functions_scope


section .data
    fmt db "sum = %d", 10, 0      ; Format string


section .text
    extern printf
    global main


main:
    ; Call add(2, 3) (like: int sum = add(2, 3);)
    mov edi, 2          ; 1st arg: a = 2
    mov esi, 3          ; 2nd arg: b = 3
    call add            ; call add(a, b)
    mov esi, eax        ; esi = sum (return value)
    mov edi, fmt        ; 1st arg: format string
    xor eax, eax        ; rax = 0 for printf
    call printf         ; printf("sum = %d\n", sum);
    mov eax, 0
    ret

; int add(int a, int b) { return a + b; }
add:
    mov eax, edi        ; eax = a
    add eax, esi        ; eax += b
    ret
