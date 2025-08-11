# GCC Compilation Options and Step-by-Step Workflow

This guide explains how to use GCC to compile C code step by step, with recommended flags for different situations.

---

## 1. Preprocessing Only (`-E`)
- **Purpose:** Expand macros, includes, and conditionals. Output is preprocessed C source.
- **Command:**
  ```sh
  gcc -E file.c -o file.i
  ```
- **When to use:** Debugging macro expansion, header inclusion, or conditional compilation issues.

---

## 2. Compile to Assembly (`-S`)
- **Purpose:** Convert preprocessed C to assembly code for your CPU.
- **Command:**
  ```sh
  gcc -S file.c -o file.s
  ```
- **When to use:** Inspecting compiler output, learning assembly, or debugging code generation.
- **Useful flags:**
  - `-O0` (no optimization, easier to read)
  - `-O2` or `-O3` (see optimized output)

---

## 3. Assemble to Object File (`-c`)
- **Purpose:** Convert assembly to machine code (object file, not yet executable).
- **Command:**
  ```sh
  gcc -c file.c -o file.o
  ```
- **When to use:** Building multi-file projects, or linking later.
- **Useful flags:**
  - `-g` (include debug symbols)
  - `-Wall` (enable all warnings)

---

## 4. Link to Executable
- **Purpose:** Combine object files and libraries into a runnable program.
- **Command:**
  ```sh
  gcc file.o -o program
  ```
- **When to use:** Final step to produce an executable.
- **Useful flags:**
  - `-static` (static linking, rarely needed)
  - `-lm` (link math library if using math functions)

---

## 5. All-in-One (Typical Usage)
- **Command:**
  ```sh
  gcc -Wall -g -O2 file.c -o program
  ```
- **Flags explained:**
  - `-Wall` : Enable all common warnings (highly recommended)
  - `-g`    : Include debug symbols (for gdb/lldb)
  - `-O2`   : Good optimization (use `-O0` for debugging, `-O3` for max speed)
  - `-o`    : Set output filename

---

## 6. Best Flags for Different Situations

| Situation         | Recommended Flags                | Why?                         |
|------------------|----------------------------------|------------------------------|
| Debugging        | `-Wall -g -O0`                   | All warnings, debug info, no optimization (easier to debug) |
| Release/Prod     | `-Wall -O2` or `-Wall -O3`       | Warnings, optimized code     |
| Learning/Reverse | `-Wall -g -O0`                   | See readable assembly, debug |
| Size critical    | `-Os`                            | Optimize for small size      |
| Static binary    | `-static`                        | No dynamic libs (rare)       |

---

## 7. Inspecting Each Stage

| Stage          | Command Example           | Output File | Notes                    |
|----------------|--------------------------|-------------|--------------------------|
| Preprocess     | `gcc -E file.c -o file.i`| `.i`        | Fully expanded source    |
| Compile to asm | `gcc -S file.c -o file.s`| `.s`        | Human-readable assembly  |
| Assemble       | `gcc -c file.c -o file.o`| `.o`        | Machine code, not linked |
| Link           | `gcc file.o -o file`     | executable  | Ready to run             |

---

## 8. Other Useful Flags
- `-std=c99` or `-std=c11` : Specify C standard
- `-pedantic` : Enforce strict standard compliance
- `-Wextra` : More warnings
- `-Werror` : Treat warnings as errors
- `-I<dir>` : Add include directory
- `-L<dir>` : Add library directory
- `-DNAME=VALUE` : Define macro for preprocessor

---

## 9. Example: Full Debug Build, Step by Step
```sh
gcc -E -Wall -g -O0 file.c -o file.i   # Preprocess
gcc -S -Wall -g -O0 file.i -o file.s   # Compile to assembly
gcc -c -Wall -g -O0 file.s -o file.o   # Assemble
gcc -Wall -g -O0 file.o -o program     # Link
```

---

For more, see `man gcc` or `gcc --help`.
