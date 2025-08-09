#include <stdio.h>
#define N 10 // Define a constant for array size (10 elements)
#define M 20 // Define a constant for matrix column size (20 elements)

int main()
{
    // 1. Array declarations
    char letters[N];      // Declare an array of 10 chars (letters)
    int numbers[N], i, j; // Declare an array of 10 ints (numbers) and loop variables
    int matrix[N][M];     // Declare a 2D array (matrix) with 10 rows and 20 columns

    // 2. Declare pointer variables for array manipulation
    char *cptr = NULL; // Pointer to char, will be used to walk through letters[]
    int *iptr = NULL;  // Pointer to int, will be used to walk through numbers[]

    // 3. Initialize pointers to the base address of the arrays
    // cptr now points to the first element of letters[]
    cptr = &(letters[0]); // Equivalent to: cptr = letters;
    // iptr now points to the first element of numbers[]
    iptr = numbers; // numbers is equivalent to &numbers[0]

    // 4. Use pointer arithmetic to initialize letters and numbers arrays
    // This loop assigns values to each element using pointers
    for (i = 0; i < N; i++)
    {
        *cptr = 'a' + i; // Assign the i-th letter ('a' to 'j') to the current char pointer
        *iptr = i * 3;   // Assign i*3 to the current int pointer (0, 3, 6, ...)
        cptr++;          // Move the char pointer to the next element in letters[]
        iptr++;          // Move the int pointer to the next element in numbers[]
    }

    // 5. Print the letters array using pointer arithmetic
    printf("letters: ");
    // Reset cptr to the start of letters[] and print each character
    for (cptr = letters, i = 0; i < N; i++, cptr++)
    {
        printf("%c ", *cptr); // Dereference cptr to get the value at that address
    }
    printf("\n");

    // 6. Print the numbers array using pointer arithmetic
    printf("numbers: ");
    // Reset iptr to the start of numbers[] and print each integer
    for (iptr = numbers, i = 0; i < N; i++, iptr++)
    {
        printf("%d ", *iptr); // Dereference iptr to get the value at that address
    }
    printf("\n");

    // 7. Example: Fill and print a 2D matrix using pointer arithmetic
    // mptr will be used to walk through the entire matrix as a flat array
    int *mptr = &matrix[0][0]; // Point to the first element of the matrix
    // Fill the matrix with values 0 to N*M-1
    for (i = 0; i < N * M; i++)
    {
        *(mptr + i) = i; // Set the i-th element in the flat matrix
    }
    // Print the first 5 elements of the first row of the matrix
    printf("matrix[0][0..4]: ");
    for (j = 0; j < 5; j++)
    {
        printf("%d ", matrix[2][j]); // Access as a 2D array for clarity
    }
    printf("\n");

    // 8. End of program
    return 0;
}
