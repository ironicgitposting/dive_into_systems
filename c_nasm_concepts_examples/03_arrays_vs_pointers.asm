
; Example 3: Arrays vs. pointers in x64 NASM Assembly
; --------------------------------------------------
; Demonstrates accessing array elements via pointer arithmetic.
; 
; MEMORY & REGISTER OVERVIEW:
; - arr: Array of 3 integers (like int arr[3] = {10, 20, 30}; in C)
; - lea: Loads the address of an array element (like &arr[1] in C)
; - [arr + 4]: Accesses arr[1] (4 bytes per int)
; - rsi: Used for passing addresses (function argument)
; - eax, edx: Used for loading int values
; - rdi: 1st function argument (format string)
; - esi, edx: 2nd and 3rd function arguments (int values)
; 
; C EQUIVALENT:
; int arr[3] = {10, 20, 30};
; printf("arr[1] = %d, *(p+1) = %d\n", arr[1], *(arr+1));
; 
; Run with: nasm -f elf64 03_arrays_vs_pointers.asm && gcc -no-pie -o 03_arrays_vs_pointers 03_arrays_vs_pointers.o && ./03_arrays_vs_pointers


section .data
    arr dd 10, 20, 30                  ; int arr[3] = {10, 20, 30};
    fmt db "arr[1] = %d, *(p+1) = %d", 10, 0 ; Format string


section .text
    extern printf
    global main


main:
    ; lea rsi, [arr + 4] loads address of arr[1] (like: int *p = &arr[1];)
    lea rsi, [arr + 4]        ; rsi = &arr[1]

    ; mov eax, [arr + 4] loads value of arr[1] (like: arr[1])
    mov eax, [arr + 4]        ; eax = arr[1]

    ; mov edx, [arr + 4] loads value at *(p+1) (same as arr[1])
    mov edx, [arr + 4]        ; edx = *(arr+1)

    ; Set up printf arguments
    mov rdi, fmt              ; 1st arg: format string
    mov esi, eax              ; 2nd arg: arr[1]
    mov edx, edx              ; 3rd arg: *(p+1)
    xor eax, eax              ; rax = 0 for printf
    call printf

    mov eax, 0
    ret
