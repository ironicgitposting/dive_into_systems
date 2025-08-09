
# x64 NASM Assembly: Core Operations Reference (with C Equivalents)

This guide explains the most important x64 NASM instructions, what they do in memory, and their C equivalents. It also defines key terms (registers, syscall arguments, etc.) to help you connect assembly to C.

---


## 1. Data Movement
- `mov dest, src` — Copy data from `src` to `dest`.
  - **Memory effect:** If `dest` is a register, its value is replaced. If `dest` is memory (e.g., `[rbx]`), the memory at that address is updated.
  - **C equivalent:** `a = b;` or `*p = x;`
- `lea reg, [mem]` — Load the address (not the value) of `[mem]` into `reg` (pointer arithmetic).
  - **Memory effect:** No memory is read or written, just computes an address.
  - **C equivalent:** `p = &arr[i];` or pointer math like `p = arr + 3;`
- `push reg` / `pop reg` — Push value onto stack / pop value from stack.
  - **Memory effect:** `push` decreases `rsp` and writes to stack; `pop` reads from stack and increases `rsp`.
  - **C equivalent:** Used for function calls/returns, like saving local variables or return addresses.


## 2. Arithmetic
- `add dest, src` — `dest = dest + src;`
- `sub dest, src` — `dest = dest - src;`
- `imul dest, src` — `dest = dest * src;`
- `inc reg` / `dec reg` — Increment/decrement register (`reg++` / `reg--`)
  - **Memory effect:** Changes the value in the register or memory location.
  - **C equivalent:** `a += b;`, `a -= b;`, `a *= b;`, `a++;`, `a--;`


## 3. Logic/Bitwise
- `and`, `or`, `xor`, `not` — Bitwise operations (like `a & b`, `a | b`, `a ^ b`, `~a` in C)
- `shl`, `shr` — Shift left/right (like `a << n`, `a >> n` in C)
  - **Memory effect:** Changes the value in the register or memory location.


## 4. Comparison and Jumps
- `cmp a, b` — Compare `a` and `b` (sets flags, does not change values)
  - **C equivalent:** Used in `if (a == b)` or `while (a < b)`
- `test a, b` — Bitwise AND, sets flags (like `if (a & b)`)
- `je`, `jne`, `jg`, `jl`, `jge`, `jle` — Jump if equal, not equal, greater, less, etc.
  - **C equivalent:** `if/else` or `while`/`for` loops
- `jmp label` — Unconditional jump (like `goto` in C)


## 5. Function Calls and Returns
- `call func` — Call a function (pushes return address, jumps to `func`)
  - **C equivalent:** `func();`
- `ret` — Return from function (pops return address from stack)
  - **C equivalent:** `return;`
- `extern` — Declare external function (e.g., `printf`)
  - **C equivalent:** `extern int printf(const char*, ...);`
- `global` — Make symbol visible to linker (e.g., `main`)
  - **C equivalent:** Makes a function visible to the linker (like not using `static` in C)


## 6. Registers (What are they?)
- Registers are like variables inside the CPU. They are very fast to access.
  - General purpose: `rax`, `rbx`, `rcx`, `rdx`, `rsi`, `rdi`, `rbp`, `rsp`, `r8`-`r15`
    - Example: `rax` is often used for return values, `rdi`/`rsi` for function arguments.
  - 32/16/8-bit: `eax`/`ax`/`al` are the lower parts of `rax` (32/16/8 bits)
  - Floating point: `xmm0`-`xmm15` (used for float/double values)
  - **C equivalent:** Local variables, function arguments, return values.


## 7. Memory Access
- `[reg]` — Value at address in `reg` (dereference pointer)
  - **C equivalent:** `*p` if `reg` holds a pointer
- `[reg+offset]` — Value at address `reg+offset` (array access)
  - **C equivalent:** `p[offset]` or `*(p + offset)`
- `mov [mem], reg` — Store value from `reg` at memory location `[mem]`
  - **C equivalent:** `*p = x;`


## 8. System Calls (Linux)
- **System call:** A direct request to the Linux kernel (e.g., to read/write files, exit, etc.)
- `mov rax, syscall_number` — Set the syscall number (which operation to perform)
  - **C equivalent:** `read()`, `write()`, `exit()`, etc. (but in C, you call a function; in assembly, you set up registers and use `syscall`)
- `mov rdi, arg1`, `mov rsi, arg2`, ... — Set syscall arguments
  - **What is a syscall argument?**: Each system call expects its parameters in specific registers:
    - `rdi` = 1st argument, `rsi` = 2nd, `rdx` = 3rd, `r10` = 4th, `r8` = 5th, `r9` = 6th
    - Example: `write(fd, buf, count)` → `rdi=fd`, `rsi=buf`, `rdx=count`
  - **C equivalent:** Passing arguments to a function, e.g., `write(fd, buf, count);`
- `syscall` — Actually perform the system call (switches to kernel mode)


## 9. Floating Point
- `movq xmm0, [mem]` — Load float/double from memory into `xmm0` register
  - **C equivalent:** `double x = *p;`
- `cvttsd2si reg, xmm0` — Convert double in `xmm0` to int in `reg`
  - **C equivalent:** `int i = (int)x;`


## 10. Macros and Constants
- `%define NAME value` — Define a constant (like `#define` in C)
- `%macro name n` ... `%endmacro` — Define a macro (like a C macro, but for assembly code)


---

## Example Patterns (with C Equivalents)
- **Print:**
  - Assembly: Set up arguments in `rdi`, `rsi`, etc., then `call printf`
  - C: `printf("x = %d\n", x);`
- **Loop:**
  - Assembly: Use `cmp`/`test` and jump instructions to repeat code
  - C: `for (int i = 0; i < n; i++) { ... }`
- **Function:**
  - Assembly: Label, use `call`, return value in `rax`
  - C: `int foo() { return 42; }`

---

**Key Terms:**
- **Register:** Fast storage inside the CPU, like a variable.
- **Stack:** Memory area for function calls, local variables, return addresses.
- **Syscall:** Direct request to the OS kernel (e.g., read, write, exit).
- **Argument:** Value passed to a function or syscall (in registers for assembly, in parentheses for C).

For more, see your `x64_asm_tutorial.md` and the [NASM documentation](https://www.nasm.us/doc/).
