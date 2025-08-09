
; Example 5: Structs and Unions in x64 NASM Assembly
; -------------------------------------------------
; Demonstrates struct-like and union-like memory usage.
; 
; MEMORY & REGISTER OVERVIEW:
; - point: 8 bytes for struct Point { int x, y; } (x at [point], y at [point+4])
; - u: 8 bytes for union Data (can hold int or float)
; - rdi: 1st function argument (format string)
; - esi, edx: 2nd and 3rd function arguments (int values)
; - xmm0: Used for float argument to printf
; - movq: Moves 64 bits between memory and xmm register
; 
; C EQUIVALENT:
; struct Point { int x, y; };
; union Data { int i; float f; };
; struct Point point = {1, 2};
; union Data u;
; printf("Point: (%d, %d)\n", point.x, point.y);
; u.i = 42;
; printf("Union as int: %d\n", u.i);
; u.f = 3.14f;
; printf("Union as float: %f\n", u.f);
; 
; Run with: nasm -f elf64 05_structs_unions.asm && gcc -no-pie -o 05_structs_unions 05_structs_unions.o && ./05_structs_unions


section .data
    fmt_point db "Point: (%d, %d)", 10, 0      ; Format for struct
    fmt_union_int db "Union as int: %d", 10, 0 ; Format for union as int
    fmt_union_float db "Union as float: %f", 10, 0 ; Format for union as float


section .bss
    point resd 2      ; Reserve 8 bytes for struct Point { int x, y; }
    u resq 1          ; Reserve 8 bytes for union Data (int or float)


section .text
    extern printf
    global main


main:
    ; Set struct Point: x=1, y=2 (like: struct Point point = {1, 2};)
    mov dword [point], 1        ; point.x = 1
    mov dword [point+4], 2      ; point.y = 2
    mov rdi, fmt_point          ; 1st arg: format string
    mov esi, [point]            ; 2nd arg: point.x
    mov edx, [point+4]          ; 3rd arg: point.y
    xor eax, eax                ; rax = 0 for printf
    call printf

    ; Set union as int (like: u.i = 42;)
    mov dword [u], 42           ; u.i = 42
    mov rdi, fmt_union_int      ; 1st arg: format string
    mov esi, [u]                ; 2nd arg: u.i
    xor eax, eax                ; rax = 0 for printf
    call printf

    ; Set union as float (bitwise, like: u.f = 3.14f;)
    mov dword [u], 0x4048f5c3   ; 3.14f in IEEE-754
    mov rdi, fmt_union_float    ; 1st arg: format string
    movq xmm0, [u]              ; xmm0 = u.f
    xor eax, eax                ; rax = 0 for printf
    call printf

    mov eax, 0
    ret
