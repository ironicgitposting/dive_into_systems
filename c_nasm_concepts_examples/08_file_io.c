#include <stdio.h>

// Example 8: File I/O in C
// ------------------------
// C uses FILE pointers and functions from <stdio.h> for file operations.
// fopen opens a file, fprintf writes to it, fclose closes it.

int main()
{
    // Open a file named "test.txt" for writing ("w" mode)
    FILE *f = fopen("test.txt", "w");
    if (!f)
        return 1; // If opening fails, exit with error

    // Write a string to the file
    fprintf(f, "Hello, file!\n");

    // Close the file to flush and release resources
    fclose(f);

    // Summary:
    // - fopen returns a FILE* (or NULL on error)
    // - fprintf works like printf but writes to a file
    // - Always close files with fclose
    return 0;
}
