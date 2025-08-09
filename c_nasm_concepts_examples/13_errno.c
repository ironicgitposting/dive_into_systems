#include <stdio.h>
#include <errno.h>
#include <string.h>

// Example 13: Error Handling with errno in C
// -----------------------------------------
// Many C library functions set the global variable errno when an error occurs.
// strerror(errno) returns a human-readable string for the error code.

int main()
{
    // Try to open a file that does not exist (should fail)
    FILE *f = fopen("nonexistent.txt", "r");
    if (!f)
    {
        // Print the error message corresponding to errno
        printf("Error: %s\n", strerror(errno));
    }

    // Summary:
    // - errno is set by system/library calls on error
    // - strerror(errno) gives a readable error message
    // - Always check for errors when working with files, memory, etc.
    return 0;
}
