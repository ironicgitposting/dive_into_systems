
; Example 6: Typedef and Enum in x64 NASM Assembly
; -----------------------------------------------
; C typedef and enum have no direct equivalent in assembly, but we can use constants and comments.
; This example demonstrates using symbolic constants for clarity.
; 
; MEMORY & REGISTER OVERVIEW:
; - RED, GREEN, BLUE: Symbolic constants (like enum Color { RED, GREEN, BLUE } in C)
; - fmt: Format string for printf
; - edi: 1st function argument (format string)
; - esi, edx: 2nd and 3rd function arguments (unsigned int and enum value)
; 
; C EQUIVALENT:
; typedef unsigned int uint;
; enum Color { RED=0, GREEN=1, BLUE=2 };
; uint a = 10;
; enum Color color = GREEN;
; printf("a = %u, color = %d\n", a, color);
; 
; Run with: nasm -f elf64 06_typedef_enum.asm && gcc -no-pie -o 06_typedef_enum 06_typedef_enum.o && ./06_typedef_enum


section .data
    fmt db "a = %u, color = %d", 10, 0      ; Format string

    ; Simulate enum Color { RED=0, GREEN=1, BLUE=2 }
    RED equ 0
    GREEN equ 1
    BLUE equ 2


section .text
    extern printf
    global main


main:
    ; Set a = 10 (like: uint a = 10;)
    mov edi, fmt            ; 1st arg: format string
    mov esi, 10             ; 2nd arg: a = 10
    mov edx, GREEN          ; 3rd arg: color = GREEN (1)
    xor eax, eax            ; rax = 0 for printf
    call printf
    mov eax, 0
    ret
