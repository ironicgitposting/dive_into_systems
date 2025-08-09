
; Example 14: Endianness check in x64 NASM Assembly
; ------------------------------------------------
; Checks system endianness by examining the first byte of a multi-byte value.
; 
; MEMORY & REGISTER OVERVIEW:
; - x: 4-byte integer (like int x in C)
; - rax: Used for address and value
; - al: Lower 8 bits of rax (used to check first byte)
; - rdi: 1st function argument (format string)
; - cmp: Compares first byte to 0x78
; 
; C EQUIVALENT:
; int x = 0x12345678;
; if (*(unsigned char *)&x == 0x78)
;     printf("Little endian\n");
; else
;     printf("Big endian\n");
; 
; Run with: nasm -f elf64 14_endianness.asm && gcc -no-pie -o 14_endianness 14_endianness.o && ./14_endianness


section .data
    fmt_le db "Little endian", 10, 0   ; Format string for little endian
    fmt_be db "Big endian", 10, 0      ; Format string for big endian


section .bss
    x resd 1           ; Reserve 4 bytes for int x


section .text
    extern printf
    global main


main:
    ; Set x = 0x12345678 (like: int x = 0x12345678;)
    mov dword [x], 0x12345678
    mov rax, x            ; rax = &x
    mov al, [rax]         ; al = first byte of x
    cmp al, 0x78          ; compare to 0x78
    jne .big              ; if not 0x78, big endian
    mov rdi, fmt_le       ; 1st arg: format string (little endian)
    xor eax, eax          ; rax = 0 for printf
    call printf           ; printf("Little endian\n");
    jmp .done
.big:
    mov rdi, fmt_be       ; 1st arg: format string (big endian)
    xor eax, eax          ; rax = 0 for printf
    call printf           ; printf("Big endian\n");
.done:
    mov eax, 0
    ret
