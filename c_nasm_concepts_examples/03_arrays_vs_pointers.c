#include <stdio.h>

// Example 3: Arrays vs. Pointers in C
// -----------------------------------
// Arrays and pointers are closely related in C.
// - The name of an array (e.g., arr) "decays" to a pointer to its first element.
// - You can use pointer arithmetic to access array elements.

int main()
{
    int arr[3] = {10, 20, 30}; // Declare and initialize an array of 3 ints

    // Assign a pointer to the first element of arr
    int *p = arr; // Equivalent to: int *p = &arr[0];

    // Access the second element using both array and pointer notation
    printf("arr[1] = %d, *(p+1) = %d\n", arr[1], *(p + 1));
    // arr[1] is the second element (index 1)
    // *(p+1) means: go to the next int after p (which is arr[0]), so arr[1]

    // Summary:
    // - arr[i] is equivalent to *(arr + i)
    // - p[i] is equivalent to *(p + i)
    // - Arrays and pointers are not the same, but closely related
    return 0;
}
