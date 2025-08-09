#include <stdio.h>
#include <stdlib.h>

/*
    Example: Using malloc for dynamic memory allocation in C
    This program demonstrates how to:
    - Allocate memory for an array at runtime
    - Check for allocation errors
    - Use the allocated memory
    - Free the memory when done
*/

int main() {
    int n, i;
    int *arr = NULL; // Pointer for the dynamic array

    // 1. Ask the user for the array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // 2. Allocate memory for n integers using malloc
    // malloc returns a void pointer, so we cast it to int*
    arr = (int *)malloc(n * sizeof(int));

    // 3. Always check if malloc succeeded
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if allocation failed
    }

    // 4. Use the allocated memory (initialize and print)
    for (i = 0; i < n; i++) {
        arr[i] = i * i; // Store the square of i
    }
    printf("Array contents: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 5. Free the allocated memory when done
    free(arr);
    arr = NULL; // Good practice: set pointer to NULL after freeing

    return 0;
}
