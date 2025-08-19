#include <stdio.h>
#include <stdlib.h>

#define COLS (100)

/**
 * Memory layout for arrays is as follows for int as an example:
 *
 * Address Element
 * 0x00    arr[0][0] // row 0, column 0
 * 0x04    arr[0][1] // row 0, column 1
 * 0x08    arr[0][2] // row 0, column 2
 * 0x0C    arr[0][3] // row 0, column 3
 * 0x10    arr[1][0] // row 1, column 0
 * 0x14    arr[1][1] // row 1, column 1
 * 0x18    arr[1][2] // row 1, column 2
 * 0x1C    arr[1][3] // row 1, column 3
 * 0x20    arr[2][0] // row 2, column 0
 * 0x24    arr[2][1] // row 2, column 1
 * 0x28    arr[2][2] // row 2, column 2
 * 0x2C    arr[2][3] // row 2, column 3
 *
 * All array elements are stored in contiguous memory locations.
 */

int main()
{
    // Static 2D array example

    // Declare a 2D array with 3 rows and COLS columns
    int arr[3][COLS];

    // Initialize the 2D array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = i * COLS + j; // Fill with some values
        }
    }

    // Print the 2D array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Dynamic 2D array example

    // Make a single call to malloc to allocate memory for a 2D array
    // allocating one big chunk of heap memory to store all N X M elements
    int rows = 3, cols = COLS;
    int *dynamic_arr = malloc(rows * cols * sizeof(int));
    if (!dynamic_arr)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Initialize the dynamic 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            dynamic_arr[i * cols + j] = i * cols + j; // Fill with some values
        }
    }
    // Print the dynamic 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", dynamic_arr[i * cols + j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(dynamic_arr);
    dynamic_arr = NULL; // Avoid dangling pointer

    return 0;
}