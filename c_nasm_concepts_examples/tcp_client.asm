; Example: Simple TCP client in x64 NASM (Linux)
; Connects to 127.0.0.1:8080 and sends "Hello, server!"
; Assemble: nasm -f elf64 tcp_client.asm && ld -o tcp_client tcp_client.o

section .data
    ip      db 127,0,0,1
    port    dw 0x1f90              ; 8080 in hex, network byte order
    msg     db "Hello, server!",0
    msglen  equ $-msg

section .bss
    sockfd  resd 1
    addr    resb 16                ; struct sockaddr_in

section .text
    global _start

_start:
    ; socket(AF_INET, SOCK_STREAM, 0)
    mov eax, 41                   ; sys_socket
    mov edi, 2                    ; AF_INET
    mov esi, 1                    ; SOCK_STREAM
    xor edx, edx                  ; protocol 0
    syscall
    mov [sockfd], eax

    ; Prepare sockaddr_in (sin_family=AF_INET, sin_port=8080, sin_addr=127.0.0.1)
    mov byte [addr], 2            ; sin_family = AF_INET
    mov word [addr+2], port       ; sin_port = htons(8080)
    mov dword [addr+4], 0x0100007f; sin_addr = 127.0.0.1 (little endian)

    ; connect(sockfd, addr, 16)
    mov eax, 42                   ; sys_connect
    mov edi, [sockfd]
    lea rsi, [addr]
    mov edx, 16
    syscall

    ; send(sockfd, msg, msglen, 0)
    mov eax, 44                   ; sys_sendto
    mov edi, [sockfd]
    mov rsi, msg
    mov edx, msglen
    xor r10d, r10d                ; flags = 0
    syscall

    ; close(sockfd)
    mov eax, 3                    ; sys_close
    mov edi, [sockfd]
    syscall

    ; exit(0)
    mov eax, 60
    xor edi, edi
    syscall
