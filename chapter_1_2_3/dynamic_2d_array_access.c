/*
    Title: Mapping 2D indices to a 1D contiguous block in C (row-major order)
    Purpose: Teach how to allocate, index, and reason about 2D data that lives
             in ONE contiguous malloc'ed block — and how that differs from
             (1) true 2D arrays and (2) pointer-to-pointer "jagged" arrays.

    TL;DR:
      - In row-major C, element [i][j] lives at linear index i * COLS + j.
      - If you malloc a single block of N*COLS ints, you can access [i][j] as
            block[i * COLS + j]
      - You can ALSO view the same block as a "2D" pointer with the right type:
            int (*A)[COLS] = (int (*)[COLS])block;  // then use A[i][j]
      - This is contiguous and cache-friendly.

    CONTRAST:
      1) True 2D array (compile-time dimensions, contiguous):
         int arr[N][M];              // contiguous in row-major
         arr[i][j] works; sizeof(arr) == N*M*sizeof(int)

      2) Pointer-to-pointer (NOT necessarily contiguous):
         int **pp = malloc(N * sizeof *pp);
         for (int i = 0; i < N; i++) {
             pp[i] = malloc(M * sizeof *pp[i]);
         }
         // Access with pp[i][j], BUT rows are separate mallocs (jagged).
         // Not a single contiguous block; worse for cache locality.

    SAFETY & STYLE NOTES:
      - Do NOT cast malloc in C: int *p = malloc(count * sizeof *p);  // good
      - Always check malloc result; free what you allocate.
      - For zero-initialization, use calloc(N * M, sizeof(int)).
      - Bounds are not checked in C — be careful with i in [0..N-1], j in [0..M-1].
*/

#include <stdio.h>
#include <stdlib.h>

/* Configure your matrix size here */
#define N 3 /* number of rows    */
#define M 4 /* number of columns */

/* Helper to compute the 1D index from 2D coordinates (row-major). */
static inline size_t idx_2d(size_t i, size_t j, size_t cols)
{
    /* i in [0..rows-1], j in [0..cols-1] */
    return i * cols + j;
}

int main(void)
{
    /*
        Allocate ONE contiguous block for N * M ints.
        This gives you row-major storage like: row0, then row1, then row2, ...
    */
    int *data = malloc((size_t)N * (size_t)M * sizeof *data);
    if (!data)
    {
        fprintf(stderr, "ERROR: malloc failed for %zu ints\n",
                (size_t)N * (size_t)M);
        return 1;
    }

    /*
        OPTIONAL: If you wanted zero-initialization, you could use:
          int *data = calloc((size_t)N * (size_t)M, sizeof *data);
        (Remember to remove the earlier malloc if you switch to calloc.)
    */

    /*
        Fill the block using the canonical formula:
            linear_index = i * M + j
        where M is the number of columns (the SECOND dimension).
    */
    for (size_t i = 0; i < (size_t)N; i++)
    {
        for (size_t j = 0; j < (size_t)M; j++)
        {
            data[idx_2d(i, j, M)] = (int)(i * 100 + j); /* easy-to-read pattern */
        }
    }

    /*
        PRINT #1: Access via the 1D formula [i * M + j]
    */
    puts("Matrix (access via 1D formula i*M + j):");
    for (size_t i = 0; i < (size_t)N; i++)
    {
        for (size_t j = 0; j < (size_t)M; j++)
        {
            printf("%3d ", data[idx_2d(i, j, M)]);
        }
        putchar('\n');
    }
    putchar('\n');

    /*
        PRINT #2: Reinterpret the same contiguous block as a pointer-to-array
                  so we can use natural A[i][j] syntax without copying.

        KEY IDEA:
          If you know the number of columns (M), you can make a pointer with
          type "pointer to array of M ints":  int (*)[M]
          and point it at the same memory.

          Then A[i][j] works exactly like a true 2D array — but you're still
          using the SAME malloc'ed contiguous block underneath.
    */
    int (*A)[M] = (int (*)[M])data; /* Reinterpretation for indexing sugar */
    puts("Matrix (same memory, accessed via A[i][j] after pointer cast):");
    for (size_t i = 0; i < (size_t)N; i++)
    {
        for (size_t j = 0; j < (size_t)M; j++)
        {
            printf("%3d ", A[i][j]); /* identical values as above */
        }
        putchar('\n');
    }
    putchar('\n');

    /*
        SCHEMA: Where each [i][j] lands in linear memory (M = number of columns)

        Linear index = i * M + j

        [0][0] -> 0*M + 0 =  0
        [0][1] -> 0*M + 1 =  1
        [0][2] -> 0*M + 2 =  2
        [0][3] -> 0*M + 3 =  3
        [1][0] -> 1*M + 0 =  4
        [1][1] -> 1*M + 1 =  5
        [1][2] -> 1*M + 2 =  6
        [1][3] -> 1*M + 3 =  7
        [2][0] -> 2*M + 0 =  8
        [2][1] -> 2*M + 1 =  9
        [2][2] -> 2*M + 2 = 10
        [2][3] -> 2*M + 3 = 11

        Example: [2][1] is at 2*4 + 1 = 9   (the 10th int in memory)
    */

    /*
        CONTRAST SECTION (for learners) — not executed:

        1) True 2D array (compile-time dimensions, contiguous):
            int arr[N][M];           // contiguous block
            arr[i][j] = ...;         // natural syntax
            // Pros: Easy indexing, contiguous, works great with sizeof/sizeof(arr[0])
            // Cons: Dimensions must be known at compile time (unless you use VLA).

        2) Pointer-to-pointer "jagged" allocation (NOT contiguous):
            int **pp = malloc(N * sizeof *pp);
            if (!pp) { //handle error  }
            for (int i = 0; i < N; i++) {
                pp[i] = malloc(M * sizeof *pp[i]);
                if (!pp[i]) { //handle partial free & error  }
            }
            // Access with pp[i][j] but rows are separate allocations.
            // Pros: Rows can have different lengths (jagged).
            // Cons: Not contiguous; worse cache behavior; more error-prone; more frees.

        BEST PRACTICE for dense matrices: prefer ONE contiguous block.
        If you want A[i][j] syntax, use the pointer-to-array trick shown above.




*/
    free(data);
    data = NULL; // Avoid dangling pointer
    return 0;
}
