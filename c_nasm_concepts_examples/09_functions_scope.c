#include <stdio.h>

// Example 9: Function Declaration, Prototype, and Scope in C
// ----------------------------------------------------------
// Functions can be declared as static to limit their scope to the current file.
// This is useful for encapsulation and avoiding name conflicts in multi-file projects.

// Declare a static function (only visible in this file)
static int add(int a, int b)
{
    return a + b; // Return the sum of a and b
}

int main()
{
    // Call the add function
    int sum = add(2, 3);
    printf("sum = %d\n", sum);

    // Summary:
    // - static before a function means file scope (not visible to other files)
    // - Function prototypes are needed if you call a function before its definition
    // - Functions help organize and reuse code
    return 0;
}
