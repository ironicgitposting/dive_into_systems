#include <stdio.h>

// Example 5: Structs and Unions in C
// -----------------------------------
// A struct is a user-defined type that groups variables under one name.
// Each member has its own memory and can be accessed independently.
// A union is similar, but all members share the same memory location.
// Only one member can hold a value at a time.

// Define a struct called Point with two integer members
struct Point
{
    int x, y; // x and y coordinates
};

// Define a union called Data with an int and a float
union Data
{
    int i;   // integer value
    float f; // float value (shares memory with i)
};

int main()
{
    // Struct usage: each member has its own space
    struct Point p = {1, 2};               // Initialize x=1, y=2
    printf("Point: (%d, %d)\n", p.x, p.y); // Access struct members with .

    // Union usage: all members share the same memory
    union Data d;
    d.i = 42;                            // Set the int member
    printf("Union as int: %d\n", d.i);   // Prints 42
    d.f = 3.14f;                         // Now set the float member (overwrites the int)
    printf("Union as float: %f\n", d.f); // Prints 3.14
    // Note: After writing to d.f, d.i will contain garbage
    printf("Union as int after float: %d (garbage)\n", d.i);

    // Summary:
    // - Use structs when you want to group related data (each member independent)
    // - Use unions when you want to store different types in the same memory (one at a time)
    return 0;
}
