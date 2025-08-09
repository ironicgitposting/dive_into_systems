#include <stdio.h>

// Example 11: Casting and Type Conversions in C
// --------------------------------------------
// Casting is used to convert a value from one type to another.
// Explicit casting is done with (type) before a value or variable.

int main()
{
    double d = 3.7; // A double (floating-point) value
    int i = (int)d; // Explicitly cast double to int (fractional part is dropped)

    printf("d = %f, i = %d\n", d, i); // Shows original and casted value

    // Summary:
    // - (int)d converts double d to int (truncates, does not round)
    // - Use casting to control type conversions and avoid warnings
    // - Implicit conversions also happen (e.g., assigning int to double)
    return 0;
}
