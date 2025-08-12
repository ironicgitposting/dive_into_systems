// pass_by_pointer.c
// Demonstrates pass-by-pointer: function modifies a variable and returns its old value
#include <stdio.h>

// Function: change_value
// Takes a pointer to int, sets the value at that address to 100,
// and returns the original value.
int change_value(int *input)
{
    int old = *input; // Save the original value
    *input = 100;     // Change the value at the address
    return old;       // Return the original value
}

int main()
{
    int x;
    int y;
    x = 30;
    y = change_value(&x);
    printf("x: %d y: %d\n", x, y); // prints x: 100 y: 30
    return 0;
}
