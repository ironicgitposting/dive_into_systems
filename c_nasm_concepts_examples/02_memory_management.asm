
; Example 2: Dynamic memory allocation in x64 NASM Assembly
; --------------------------------------------------------
; This program allocates memory on the heap using malloc, writes values, prints them, and frees the memory.
; 
; MEMORY OVERVIEW:
; - The heap is a region of memory for dynamic allocation (like malloc in C).
; - The stack is used for function calls, local variables, and return addresses.
; - Registers are small, fast storage locations inside the CPU (like variables, but much faster).
;   - rax, rbx, rcx, rdx, rsi, rdi, rbp, rsp, r8-r15: 64-bit general purpose registers.
;   - rdi, rsi, rdx, rcx, r8, r9: Used for function arguments (in that order) in x64 calling convention.
;   - rax: Used for return values from functions.
;   - rbx: Here, used to store the pointer returned by malloc (like int *arr in C).
;   - rcx: Used as a loop counter (like int i in C).
;   - eax, ebx, ecx, edx: Lower 32 bits of rax, rbx, rcx, rdx (used for int values).
; - [rbx + rcx*4]: Accesses the (rcx)th int in the array pointed to by rbx (like arr[i] in C).
; 
; C EQUIVALENT:
; int n = 5;
; int *arr = malloc(n * sizeof(int));
; for (int i = 0; i < n; i++) arr[i] = i * 2;
; for (int i = 0; i < n; i++) printf("arr[%d] = %d\n", i, arr[i]);
; free(arr);
; 
; Run with: nasm -f elf64 02_memory_management.asm && gcc -no-pie -o 02_memory_management 02_memory_management.o && ./02_memory_management



section .data
    fmt db "arr[%d] = %d", 10, 0   ; Format string for printf ("arr[i] = value\n")
    fmt2 db "Static: %d Dynamic: %d", 10, 0 ; Format for static/dynamic print
    n dq 5                         ; n = 5 (array size)



section .bss
    s_array resd 20                ; int s_array[20] (static array)

section .text
    extern printf, malloc, free     ; Declare external C library functions
    global main



main:
    ; --- Dynamic allocation for arr[5] (original example) ---
    mov rdi, 20              ; rdi = 20 (bytes to allocate), 5 * 4 = 20
    call malloc              ; malloc(20), returns pointer in rax
    mov rbx, rax             ; rbx = arr (save pointer to allocated memory)

    ; Store values: arr[i] = i * 2
    xor rcx, rcx             ; rcx = i = 0 (loop counter)
.loop_set:
    cmp rcx, 5               ; if (i >= 5) break
    jge .after_arr
    mov eax, ecx             ; eax = i
    shl eax, 1               ; eax = i * 2
    mov [rbx + rcx*4], eax   ; arr[i] = eax (store value at arr + i*4)
    inc rcx                  ; i++
    jmp .loop_set            ; repeat
.after_arr:

    ; Print arr[i] values
    xor rcx, rcx             ; rcx = i = 0 (reset loop counter)
.loop_print:
    cmp rcx, 5               ; if (i >= 5) break
    jge .static_dynamic
    mov eax, [rbx + rcx*4]   ; eax = arr[i] (load value from memory)
    mov rdi, fmt             ; 1st printf arg: format string
    mov esi, ecx             ; 2nd printf arg: i (as %d)
    mov edx, eax             ; 3rd printf arg: arr[i] (as %d)
    xor eax, eax             ; printf needs rax=0 for varargs
    call printf              ; printf("arr[%d] = %d\n", i, arr[i])
    inc rcx                  ; i++
    jmp .loop_print          ; repeat

    ; --- Static vs Dynamic Array Example ---
.static_dynamic:
    ; Fill s_array[20] and d_array[20] with i
    mov rdi, 80              ; 20 * 4 bytes
    call malloc              ; malloc(80)
    mov rdx, rax             ; rdx = d_array
    xor rcx, rcx             ; rcx = i = 0
.loop_fill:
    cmp rcx, 20
    jge .print_both
    mov dword [s_array + rcx*4], ecx ; s_array[i] = i
    mov dword [rdx + rcx*4], ecx     ; d_array[i] = i
    inc rcx
    jmp .loop_fill
.print_both:
    mov eax, [s_array + 12]  ; s_array[3] (3*4=12)
    mov ebx, [rdx + 12]      ; d_array[3]
    mov rdi, fmt2            ; format string
    mov esi, eax             ; static value
    mov edx, ebx             ; dynamic value
    xor eax, eax
    call printf              ; printf("Static: %d Dynamic: %d\n", s_array[3], d_array[3])
    mov rdi, rdx             ; free(d_array)
    call free

    ; Free arr from original example
    mov rdi, rbx
    call free
    mov eax, 0
    ret
