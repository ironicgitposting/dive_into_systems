#include <stdio.h>

// Example 1: Basic pointer usage in C
// -----------------------------------
// A pointer is a variable that stores the memory address of another variable.
// You can use pointers to directly access and modify memory.

int main()
{
    int x = 42; // Declare an integer variable and assign it a value

    // Declare a pointer to int and assign it the address of x
    int *p = &x; // &x gives the address of x

    // Print the value of x
    printf("x = %d\n", x);

    // Print the address of x in memory
    printf("Address of x: %p\n", (void *)&x);

    // Print the value stored in pointer p (should be the address of x)
    printf("p points to: %p\n", (void *)p);

    // Dereference the pointer p to get the value at that address (should be 42)
    printf("Value at p: %d\n", *p); // *p means 'the value at the address p points to'

    // Summary:
    // - &x gets the address of x
    // - p stores that address
    // - *p accesses the value at that address
    return 0;
}
