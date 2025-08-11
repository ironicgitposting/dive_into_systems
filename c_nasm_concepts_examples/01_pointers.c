#include <stdio.h>

// Example 1: Basic pointer usage and pass-by-pointer in C
// ------------------------------------------------------
// A pointer is a variable that stores the memory address of another variable.
// You can use pointers to directly access and modify memory.
// Passing a pointer to a function allows the function to modify the original variable.

/*
Without Pointer (Pass-by-Value)

#include <stdio.h>

void changeValue(int x) {
    x = 20;  // Changes only the local copy
}

int main() {
    int a = 10;
    changeValue(a);
    printf("a = %d\n", a); // a is still 10
    return 0;
}

Result: a = 10
Why? x is just a copy of a.
With Pointer (Pass-by-Pointer)

With Pointer (Pass-by-Pointer)

#include <stdio.h>

void changeValue(int *x) {
    *x = 20;  // Go to the address and change the value there
}

int main() {
    int a = 10;
    changeValue(&a);  // Pass the address of 'a'
    printf("a = %d\n", a); // a is now 20
    return 0;
}

*/

#include <stdio.h>

void changeValue(int *x)
{
    *x = 20; // Go to the address and change the value there
}

int main()
{
    int a = 10;
    changeValue(&a);       // Pass the address of 'a'
    printf("a = %d\n", a); // a is now 20
    return 0;
}

void set_to_100(int *ptr)
{
    // This function sets the value at the address pointed to by ptr to 100
    *ptr = 100;
}

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

    // Pass by pointer: modify x via a function
    printf("\nCalling set_to_100(p)...\n");
    set_to_100(p);
    printf("x after set_to_100(p): %d\n", x);
    printf("Value at p after set_to_100: %d\n", *p);

    // Summary:
    // - &x gets the address of x
    // - p stores that address
    // - *p accesses the value at that address
    // - Passing p to a function allows the function to modify x directly
    return 0;
}
