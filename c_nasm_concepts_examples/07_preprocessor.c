#include <stdio.h>

// Example 7: Preprocessor Macros in C
// -----------------------------------
// The preprocessor runs before compilation and handles directives like #define and #include.
// Macros can define constants or code snippets that are textually substituted before compilation.

#define PI 3.14159            // Define a constant for PI
#define SQUARE(x) ((x) * (x)) // Define a macro to compute the square of a value

int main()
{
    // Use the PI macro (replaces PI with 3.14159)
    printf("PI = %f\n", PI);
    

    // Use the SQUARE macro (replaces SQUARE(4) with ((4) * (4)))
    printf("SQUARE(4) = %d\n", SQUARE(4));

    // Summary:
    // - #define creates macros for constants or code
    // - Macros are replaced by the preprocessor before compilation
    // - Be careful with macro arguments and parentheses!
    return 0;
}
