
; Example 13: Error handling with errno in x64 NASM Assembly (Linux syscall)
; -------------------------------------------------------------------------
; This example tries to open a non-existent file and prints the error using perror.
; 
; MEMORY & REGISTER OVERVIEW:
; - filename: Pointer to file name string (like char *filename = "nonexistent.txt"; in C)
; - msg: Error message string (like char *msg = "Error opening file";)
; - rdi, rsi: Used for function arguments (filename, mode, error message)
; - rax: Used for return value from fopen (FILE * or NULL)
; - test: Checks if rax is zero (NULL)
; - perror: Prints error message based on errno
; 
; C EQUIVALENT:
; FILE *f = fopen("nonexistent.txt", "r");
; if (!f) perror("Error opening file");
; 
; Run with: nasm -f elf64 13_errno.asm && gcc -no-pie -o 13_errno 13_errno.o && ./13_errno


section .data
    filename db "nonexistent.txt", 0     ; char *filename = "nonexistent.txt";
    msg db "Error opening file", 0        ; char *msg = "Error opening file";


section .text
    extern fopen, perror
    global main


main:
    ; Try to open file (like: FILE *f = fopen(filename, "r");)
    mov rdi, filename       ; 1st arg: filename
    mov rsi, "r"           ; 2nd arg: mode ("r")
    call fopen              ; fopen(filename, "r")
    test rax, rax           ; check if rax == 0 (NULL)
    jnz .done               ; if not NULL, skip error
    mov rdi, msg            ; 1st arg: error message
    call perror             ; perror(msg)
.done:
    mov eax, 0
    ret
