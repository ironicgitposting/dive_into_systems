#include <stdio.h>
#include <stdlib.h>

// Example 2: malloc, free, and memory safety in C
// -----------------------------------------------
// malloc is used to allocate memory dynamically at runtime.
// You must always free memory you allocate with malloc to avoid memory leaks.

int main()
{
    int n = 5; // Number of elements for the array

    // Allocate memory for 5 integers (n * sizeof(int) bytes)
    // malloc returns a void pointer, so we assign it to an int pointer
    int *arr = malloc(n * sizeof(int));

    // Always check if malloc succeeded (returns NULL on failure)
    if (!arr)
    {
        printf("Allocation failed!\n");
        return 1;
    }

    // Use the allocated memory (initialize the array)
    for (int i = 0; i < n; i++)
        arr[i] = i * 2; // Store even numbers: 0, 2, 4, 6, 8

    // Print the array contents
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Free the allocated memory when done
    free(arr); // Always free memory allocated with malloc!

    // Summary:
    // - malloc allocates memory on the heap
    // - Always check for NULL
    // - Always free what you malloc
    return 0;
}
