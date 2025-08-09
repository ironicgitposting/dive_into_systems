#include <stdio.h>

// Example 15: Inline Assembly in C (GCC syntax, x86)
// --------------------------------------------------
// Inline assembly lets you write assembly code inside C for low-level control.
// This example adds two integers using x86 assembly instructions.

int main()
{
    int a = 5, b = 3, result;

    // Inline assembly block:
    // - "addl %%ebx, %%eax;" is the assembly instruction (add ebx to eax)
    // - Output: "=a"(result) means store eax in result after execution
    // - Inputs: "a"(a) loads a into eax, "b"(b) loads b into ebx
    __asm__("addl %%ebx, %%eax;" : "=a"(result) : "a"(a), "b"(b));

    printf("result = %d\n", result); // Should print 8

    // Summary:
    // - Inline assembly is for advanced, low-level tasks
    // - Syntax is compiler- and architecture-specific (here: GCC, x86)
    // - Use only when you need direct hardware or performance control
    return 0;
}
