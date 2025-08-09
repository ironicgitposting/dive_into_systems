
; Example 1: Basic pointer usage in x64 NASM Assembly
; --------------------------------------------------
; This program demonstrates how to use memory addresses and dereference pointers.
; It prints the value of an integer, its address, and the value via dereferencing.
; 
; MEMORY & REGISTER OVERVIEW:
; - [x]: 4 bytes for an integer (like int x in C)
; - [p]: 8 bytes for a pointer (like int *p in C)
; - rax: General purpose register, used for addresses and return values
; - rdi, rsi: Used for function arguments (1st and 2nd) in x64 calling convention
; - eax: Lower 32 bits of rax, used for int values
; - esi: Lower 32 bits of rsi, used for int arguments
; - lea: Loads the address of a variable (like &x in C)
; - [p]: Dereferences pointer p (like *p in C)
; 
; C EQUIVALENT:
; int x = 42;
; int *p = &x;
; printf("x = %d\n", x);
; printf("Address of x: %p\n", &x);
; printf("Value at p: %d\n", *p);
; 
; Run with: nasm -f elf64 01_pointers.asm && gcc -no-pie -o 01_pointers 01_pointers.o && ./01_pointers


section .data
    fmt_val db "x = %d", 10, 0           ; Format string for value ("x = %d\n")
    fmt_addr db "Address of x: %p", 10, 0 ; Format string for address ("Address of x: ...\n")
    fmt_ptr db "Value at p: %d", 10, 0    ; Format string for dereferenced pointer ("Value at p: ...\n")


section .bss
    x resd 1      ; Reserve 4 bytes for int x
    p resq 1      ; Reserve 8 bytes for pointer p (int *)


section .text
    extern printf
    global main


main:
    ; Set x = 42 (like: int x = 42;)
    mov dword [x], 42

    ; Set p = &x (like: int *p = &x;)
    lea rax, [x]         ; rax = address of x
    mov [p], rax         ; store address in p

    ; Print x (like: printf("x = %d\n", x);)
    mov rdi, fmt_val     ; 1st arg: format string
    mov eax, [x]         ; eax = x
    mov esi, eax         ; 2nd arg: x
    xor eax, eax         ; rax = 0 for printf
    call printf

    ; Print address of x (like: printf("Address of x: %p\n", &x);)
    mov rdi, fmt_addr    ; 1st arg: format string
    lea rsi, [x]         ; 2nd arg: &x
    xor eax, eax         ; rax = 0 for printf
    call printf

    ; Print value at p (like: printf("Value at p: %d\n", *p);)
    mov rdi, fmt_ptr     ; 1st arg: format string
    mov rax, [p]         ; rax = p
    mov esi, [rax]       ; esi = *p (dereference)
    xor eax, eax         ; rax = 0 for printf
    call printf

    ; Return 0
    mov eax, 0
    ret
