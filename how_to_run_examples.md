# How to Compile and Run C and x64 NASM Examples

This guide explains how to build and run the C and NASM x64 assembly example files in this folder on a Linux system.

---

## 1. C Files (`.c`)

### Compile
```sh
gcc -Wall -g -o example example.c
```
- Replace `example.c` with the filename (e.g., `01_pointers.c`).
- The `-o example` part sets the output binary name.

### Run
```sh
./example
```

---

## 2. NASM x64 Assembly Files (`.asm`)

### Compile and Link (with C library, e.g., for printf)
```sh
nasm -f elf64 example.asm -o example.o
gcc -no-pie -o example example.o
```
- Replace `example.asm` with the filename (e.g., `01_pointers.asm`).
- This produces an executable named `example`.

### Compile and Link (pure Linux syscall, no C library)
Some files (like `08_file_io.asm`) use only syscalls:
```sh
nasm -f elf64 08_file_io.asm -o 08_file_io.o
ld -o 08_file_io 08_file_io.o
```

### Run
```sh
./example
```

---

## 3. Notes
- You need `nasm`, `gcc`, and `ld` installed. Install with:
  ```sh
  sudo apt update && sudo apt install build-essential nasm
  ```
- If you see missing symbol errors, make sure you use `gcc -no-pie` for linking with C library functions.
- For pure syscalls, use `ld` directly.
- Output files may overwrite each other if you use the same name; use unique names for each example.

---

## 4. Example: Build and Run `01_pointers.asm`
```sh
nasm -f elf64 01_pointers.asm -o 01_pointers.o
gcc -no-pie -o 01_pointers 01_pointers.o
./01_pointers
```

## 4. Example: Build and Run the Pointers NASM Example

Suppose you want to run the pointers assembly example (`01_pointers.asm`):

### 1. Assemble to object file
```sh
nasm -f elf64 01_pointers.asm -o 01_pointers.o
```

### 2. Link to executable (with C library for printf)
```sh
gcc -no-pie -o 01_pointers 01_pointers.o
```

### 3. Run the program
```sh
./01_pointers
```

You should see output similar to:
```
x = 42
Address of x: 0x... (some address)
p points to: 0x... (same address)
Value at p: 42
```

---

If you have any issues, check the comments in each file or ask for help!
