
; Example 4: Strings and character arrays in x64 NASM Assembly
; -----------------------------------------------------------
; Demonstrates copying and printing a string using printf.
; 
; MEMORY & REGISTER OVERVIEW:
; - str1: Source string (like char str1[] = "hello"; in C)
; - str2: Destination buffer (like char str2[10]; in C)
; - rdi: 1st function argument (destination for strcpy, format string for printf)
; - rsi: 2nd function argument (source for strcpy, string for printf)
; - strcpy: Copies string from rsi to rdi (like strcpy in C)
; - printf: Prints string using format
; 
; C EQUIVALENT:
; char str1[] = "hello";
; char str2[10];
; strcpy(str2, str1);
; printf("str2: %s\n", str2);
; 
; Run with: nasm -f elf64 04_strings.asm && gcc -no-pie -o 04_strings 04_strings.o && ./04_strings


section .data
    str1 db "hello", 0                ; char str1[] = "hello";
    str2 times 10 db 0                 ; char str2[10];
    fmt db "str2: %s", 10, 0          ; Format string


section .text
    extern printf, strcpy
    global main


main:
    ; Copy str1 to str2 (like: strcpy(str2, str1);)
    mov rdi, str2      ; rdi = dest
    mov rsi, str1      ; rsi = src
    call strcpy        ; strcpy(str2, str1)

    ; Print str2 (like: printf("str2: %s\n", str2);)
    mov rdi, fmt       ; 1st arg: format string
    mov rsi, str2      ; 2nd arg: str2
    xor eax, eax       ; rax = 0 for printf
    call printf

    mov eax, 0
    ret
