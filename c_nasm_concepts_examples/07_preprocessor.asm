
; Example 7: Preprocessor Macros in x64 NASM Assembly
; --------------------------------------------------
; NASM supports symbolic constants and macros, similar to C preprocessor.
; This example demonstrates using %define and a macro for SQUARE.
; 
; MEMORY & REGISTER OVERVIEW:
; - %define: Defines a constant (like #define in C)
; - %macro: Defines a macro (like a C macro, but for assembly code)
; - PI: Symbolic constant (like #define PI 3.14159)
; - SQUARE: Macro to compute square of a value (like #define SQUARE(x) ((x)*(x)))
; - rdi: 1st function argument (format string)
; - xmm0: Used for float argument to printf
; - eax, esi: Used for int values and arguments
; 
; C EQUIVALENT:
; #define PI 3.14159
; #define SQUARE(x) ((x)*(x))
; printf("PI = %f\n", PI);
; printf("SQUARE(4) = %d\n", SQUARE(4));
; 
; Run with: nasm -f elf64 07_preprocessor.asm && gcc -no-pie -o 07_preprocessor 07_preprocessor.o && ./07_preprocessor

%define PI 3.14159                  ; Like: #define PI 3.14159
%macro SQUARE 1                     ; Like: #define SQUARE(x) ((x)*(x))
    imul eax, %1, %1                ; eax = %1 * %1
%endmacro


section .data
    fmt_pi db "PI = %f", 10, 0         ; Format string for PI
    fmt_sq db "SQUARE(4) = %d", 10, 0  ; Format string for SQUARE(4)


section .text
    extern printf
    global main


main:
    ; Print PI (like: printf("PI = %f\n", PI);)
    mov rdi, fmt_pi         ; 1st arg: format string
    mov eax, 0              ; rax = 0 for printf
    movq xmm0, __float64__(PI) ; xmm0 = PI (float)
    call printf

    ; Print SQUARE(4) (like: printf("SQUARE(4) = %d\n", SQUARE(4));)
    mov rdi, fmt_sq         ; 1st arg: format string
    mov eax, 4              ; eax = 4
    SQUARE 4                ; eax = 4*4 = 16
    mov esi, eax            ; 2nd arg: SQUARE(4)
    xor eax, eax            ; rax = 0 for printf
    call printf

    mov eax, 0
    ret
