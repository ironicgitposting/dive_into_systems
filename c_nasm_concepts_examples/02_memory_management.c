#include <stdio.h>
#include <stdlib.h>

// Example 2: malloc, free, and memory safety in C
// -----------------------------------------------
// malloc is used to allocate memory dynamically at runtime (on the heap).
// It returns a pointer to the allocated memory, or NULL if allocation fails.

// You must always free memory you allocate with malloc to avoid memory leaks.

// Malloc formula: sizeof(<type>) * <number of elements>

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
    {
        arr[i] = i * 2; // Store even numbers: 0, 2, 4, 6, 8
    }

    // Print the array contents
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // --- Static vs Dynamic Array Example ---
    // This demonstrates that you can use the same syntax for both static and dynamic arrays
    int i;
    int s_array[20];
    int *d_array;
    d_array = malloc(sizeof(int) * 20);
    // Always check if malloc succeeded
    if (d_array == NULL)
    {
        printf("Error: malloc failed\n");
        exit(1);
    }
    for (i = 0; i < 20; i++)
    {
        s_array[i] = i;
        d_array[i] = i;
    }

    // Array elements represent memory locations
    // The exact address of the ith element depends on the number of bytes of the type stored in the array
    // For example, for an int array, the address of the ith element is base_address
    // + (i * sizeof(int))
    // where base_address is the address of the first element of the array.
    // This means that the address of the ith element is not fixed, it depends on the size of the type stored in the array and the number of elements in the array.
    // For char arrays, the address of the ith element is base_address + (i * sizeof(char)),
    // where base_address is the address of the first element of the array.
    // For example, if the base address is 0x1000 and the size of int is 4 bytes, the address of the 3rd element (index 2) would
    // be 0x1000 + (2 * 4) = 0x1008.
    // For example, if the base address is 0x1000 and the size of
    printf("Static: %d Dynamic: %d\n", s_array[3], d_array[3]); // prints 3 3
    free(d_array);

    // Free the allocated memory when done
    free(arr); // Always free memory allocated with malloc!

    // Heap memory must be explicitly allocated and freed.

    // Summary:
    // - malloc allocates memory on the heap
    // - Always check for NULL
    // - Always free what you malloc

    // another example
    int *p;

    p = malloc(sizeof(int)); // Allocate memory for an int
    if (p != NULL)
    {
        *p = 42; // Assign a value to the allocated memory
    }
    free(p); // Free the allocated memory

    // sometimes you may see calls to malloc that explicitly cast the return value:
    p = (int *)malloc(sizeof(int)); // Cast to int pointer
    if (p != NULL)
    {
        *p = 42; // Assign a value to the allocated memory
    }
    free(p); // Free the allocated memory

    // sometimes you may see calls to malloc that explicitly cast the return value:
    p = (int *)malloc(sizeof(int)); // Cast to int pointer
    if (p != NULL)
    {
        *p = 42; // Assign a value to the allocated memory
        printf("%d\n", *p);
    }
    free(p);  // Free the allocated memory
    p = NULL; // Set pointer to NULL after freeing, this is a good practice

    return 0;
}
