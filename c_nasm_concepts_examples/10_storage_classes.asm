
; Example 10: Storage classes (static variable) in x64 NASM Assembly
; -----------------------------------------------------------------
; Demonstrates a static-like variable by keeping a value in the .bss section.
; 
; MEMORY & REGISTER OVERVIEW:
; - count: Variable in .bss section (like static int count in C)
; - ecx: Loop counter
; - eax: Used for int value and as argument to printf
; - rdi: 1st function argument (format string)
; - esi: 2nd function argument (int value)
; 
; C EQUIVALENT:
; static int count = 0;
; for (int i = 0; i < 3; i++) {
;     count++;
;     printf("count = %d\n", count);
; }
; 
; Run with: nasm -f elf64 10_storage_classes.asm && gcc -no-pie -o 10_storage_classes 10_storage_classes.o && ./10_storage_classes


section .data
    fmt db "count = %d", 10, 0      ; Format string


section .bss
    count resd 1    ; Reserve 4 bytes for static int count = 0


section .text
    extern printf
    global main


main:
    mov ecx, 3          ; Loop 3 times (for (int i = 0; i < 3; i++))
.loop:
    cmp ecx, 0
    je .done
    ; Increment static count (like: count++)
    mov eax, [count]    ; eax = count
    inc eax             ; eax++
    mov [count], eax    ; count = eax
    ; Print count (like: printf("count = %d\n", count);)
    mov rdi, fmt        ; 1st arg: format string
    mov esi, eax        ; 2nd arg: count
    xor eax, eax        ; rax = 0 for printf
    call printf
    dec ecx             ; ecx--
    jmp .loop
.done:
    mov eax, 0
    ret
