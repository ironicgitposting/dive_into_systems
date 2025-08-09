
; Example 12: Variadic function (simulated) in x64 NASM Assembly
; ------------------------------------------------------------
; Assembly does not have variadic functions, but we can simulate passing multiple arguments.
; 
; MEMORY & REGISTER OVERVIEW:
; - rdi: 1st function argument (format string)
; - esi, edx, ecx, r8d: 2nd, 3rd, 4th, 5th arguments (int values)
; - printf: Can take multiple arguments (like variadic in C)
; 
; C EQUIVALENT:
; void print_numbers(int n, ...) { printf("%d %d %d %d\n", 10, 20, 30, 40); }
; print_numbers(4, 10, 20, 30, 40);
; 
; Run with: nasm -f elf64 12_variadic.asm && gcc -no-pie -o 12_variadic 12_variadic.o && ./12_variadic


section .data
    fmt db "%d %d %d %d", 10, 0      ; Format string


section .text
    extern printf
    global main


main:
    ; Simulate variadic function call (like: print_numbers(4, 10, 20, 30, 40);)
    mov rdi, fmt            ; 1st arg: format string
    mov esi, 10             ; 2nd arg: 10
    mov edx, 20             ; 3rd arg: 20
    mov ecx, 30             ; 4th arg: 30
    mov r8d, 40             ; 5th arg: 40
    xor eax, eax            ; rax = 0 for printf
    call printf             ; printf("%d %d %d %d\n", 10, 20, 30, 40);
    mov eax, 0
    ret
