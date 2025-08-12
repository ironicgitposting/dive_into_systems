# Pass-by-Pointer Example: C and x64 Assembly

This example demonstrates how to use pass-by-pointer to modify a variable in a function and return its original value, in both C and NASM x64 assembly.

---

## C Example: `pass_by_pointer.c`
```c
#include <stdio.h>

// Function: change_value
// Takes a pointer to int, sets the value at that address to 100,
// and returns the original value.
int change_value(int *input) {
    int old = *input; // Save the original value
    *input = 100;     // Change the value at the address
    return old;       // Return the original value
}

int main() {
    int x;
    int y;
    x = 30;
    y = change_value(&x);
    printf("x: %d y: %d\n", x, y); // prints x: 100 y: 30
    return 0;
}
```

---

## NASM x64 Example: `pass_by_pointer.asm`
```nasm
section .data
    fmt db "x: %d y: %d", 10, 0

section .bss
    x resd 1
    y resd 1

section .text
    extern printf
    global main

main:
    mov dword [x], 30         ; x = 30
    lea rdi, [x]              ; rdi = &x (pointer to x)
    call change_value         ; y = change_value(&x)
    mov [y], eax              ; store return value in y
    mov eax, [x]              ; eax = x
    mov esi, [y]              ; esi = y
    mov rdi, fmt              ; rdi = format string
    xor eax, eax              ; rax = 0 for printf
    call printf               ; printf("x: %d y: %d\n", x, y)
    mov eax, 0
    ret

change_value:
    mov eax, [rdi]            ; eax = *input (old value)
    mov dword [rdi], 100      ; *input = 100
    ret
```

---

## Explanation
- **Pass-by-pointer** allows a function to modify a variable in the caller by passing its address.
- In both C and NASM, the function receives a pointer (address), dereferences it to get the value, stores the old value, writes a new value (100), and returns the old value.
- The output is:
  ```
  x: 100 y: 30
  ```
- This pattern is common for in-place modification and returning previous state.

---

## How to Build and Run

### C
```sh
gcc -o pass_by_pointer pass_by_pointer.c
./pass_by_pointer
```

### NASM (x64 Linux)
```sh
nasm -f elf64 pass_by_pointer.asm -o pass_by_pointer.o
gcc -no-pie -o pass_by_pointer pass_by_pointer.o
./pass_by_pointer
```

---

See comments in each file for line-by-line explanations.
