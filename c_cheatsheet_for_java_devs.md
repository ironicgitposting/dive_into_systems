# C Language Cheatsheet for Java Developers (Before Learning Assembly)

This guide highlights essential C features and differences for Java developers, focusing on what you need to know before diving into assembly language.

---

## 1. Basic Syntax
- **No classes or objects**: C is procedural, not object-oriented.
- **Main function**: Entry point is `int main()`.
- **Semicolons**: End every statement with `;`.
- **Braces**: Use `{}` for code blocks.

## 2. Data Types
- `int`, `float`, `double`, `char` (no `String` type; use `char[]` or pointers)
- **No boolean**: Use `int` (0 = false, nonzero = true)
- **Size**: Types have platform-dependent sizes (use `sizeof`)

## 3. Variables
- Must be declared before use.
- No access modifiers (public/private/protected).
- No variable initialization by default (uninitialized variables contain garbage values).

## 4. Input/Output
- Use `printf()` for output, `scanf()` for input (from `<stdio.h>`)
- Format specifiers: `%d` (int), `%f` (float), `%lf` (double), `%c` (char), `%s` (string)

## 5. Control Structures
- `if`, `else`, `switch`, `while`, `for`, `do-while` (syntax similar to Java)
- No enhanced for-each loop

## 6. Functions
- No method overloading
- No default parameters
- Functions can be declared before use or prototyped
- No member functions (no classes)

## 7. Arrays & Strings
- Arrays: `int arr[10];` (fixed size, no bounds checking)
- Strings: `char str[] = "hello";` or `char *str = "hello";`
- No built-in string class; use functions from `<string.h>`

## 8. Pointers
- **Key difference from Java**: Direct memory access
- Declaration: `int *p;`
- Address-of: `&var`, Dereference: `*p`
- Arrays and pointers are closely related

## 9. Memory Management
- Manual allocation: `malloc()`, `calloc()`, `free()` from `<stdlib.h>`
- No garbage collection

## 10. Structs
- Like lightweight classes (no methods)
- Example:
  ```c
  struct Point {
      int x, y;
  };
  struct Point p1;
  ```

## 11. Preprocessor
- `#include <file.h>`: Include headers
- `#define`: Macros/constants
- No import/package system

## 12. Compilation
- Compile with `gcc file.c -o output`
- No JVM; produces native binaries

## 13. Miscellaneous
- No exception handling (use return codes)
- Comments: `// single-line`, `/* multi-line */`
- No namespaces

---

## Key Differences from Java
- No OOP features (no classes, inheritance, interfaces)
- Manual memory management
- Direct pointer manipulation
- No standard library for collections, strings, or utilities
- Simpler build and execution process

---

## Example: Hello World in C
```c
#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}
```

---

## Recommended C Features to Master Before Assembly
- Data types and variable declarations
- Pointers and memory addresses
- Arrays and strings
- Control flow (if, switch, loops)
- Functions and parameter passing
- Manual memory management
- Structs

---

For more, see: [C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language)
