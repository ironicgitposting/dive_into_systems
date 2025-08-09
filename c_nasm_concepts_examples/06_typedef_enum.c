typedef unsigned int uint;
enum Color
{
    RED,
    GREEN,
    BLUE
};

int main()
{
    uint a = 10;
    enum Color c = GREEN;
    printf("a = %u, color = %d\n", a, c);
    return 0;
}
#include <stdio.h>

// Example 6: typedef and enum in C
// --------------------------------
// typedef creates an alias for a type, making code easier to read and write.
// enum defines a set of named integer constants (enumeration).

typedef unsigned int uint; // Now 'uint' can be used instead of 'unsigned int'

// Define an enumeration for colors
enum Color
{
    RED,   // 0
    GREEN, // 1
    BLUE   // 2
};

int main()
{
    uint a = 10;          // Use the typedef alias for unsigned int
    enum Color c = GREEN; // Use the enum type and assign a value

    // Print the values
    printf("a = %u, color = %d\n", a, c);
    // Note: enum values are just integers (RED=0, GREEN=1, BLUE=2)

    // Summary:
    // - typedef is for type aliases (e.g., uint for unsigned int)
    // - enum is for named integer constants (e.g., Color)
    return 0;
}
