
; Example 8: File I/O in x64 NASM Assembly (Linux syscall)
; ------------------------------------------------------
; This example writes a string to a file using Linux syscalls (no libc).
; 
; MEMORY & REGISTER OVERVIEW:
; - filename: Pointer to file name string (like char *filename = "test.txt"; in C)
; - msg: Message to write (like char msg[] = "Hello, file!\n";)
; - rax: Used for syscall number and return values
; - rdi, rsi, rdx: Used for syscall arguments (1st, 2nd, 3rd)
; - r12: Used to store file descriptor (like int fd in C)
; - syscall: Triggers a Linux system call (see man 2 syscall)
; 
; C EQUIVALENT:
; int fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
; write(fd, msg, strlen(msg));
; close(fd);
; exit(0);
; 
; Run with: nasm -f elf64 08_file_io.asm && ld -o 08_file_io 08_file_io.o && ./08_file_io


section .data
    filename db "test.txt", 0         ; char *filename = "test.txt";
    msg db "Hello, file!", 10         ; char msg[] = "Hello, file!\n";
    msglen equ $-msg                  ; int msglen = strlen(msg);


section .text
    global _start


_start:
    ; open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644)
    mov rax, 2          ; syscall: sys_open (2)
    mov rdi, filename   ; 1st arg: filename
    mov rsi, 577        ; 2nd arg: flags (O_WRONLY|O_CREAT|O_TRUNC)
    mov rdx, 0o644      ; 3rd arg: mode (octal 644)
    syscall             ; int fd = open(filename, flags, mode);
    mov r12, rax        ; save file descriptor (fd)

    ; write(fd, msg, msglen)
    mov rax, 1          ; syscall: sys_write (1)
    mov rdi, r12        ; 1st arg: fd
    mov rsi, msg        ; 2nd arg: buf
    mov rdx, msglen     ; 3rd arg: count
    syscall             ; write(fd, msg, msglen);

    ; close(fd)
    mov rax, 3          ; syscall: sys_close (3)
    mov rdi, r12        ; 1st arg: fd
    syscall             ; close(fd);

    ; exit(0)
    mov rax, 60         ; syscall: sys_exit (60)
    xor rdi, rdi        ; 1st arg: 0
    syscall             ; exit(0);
