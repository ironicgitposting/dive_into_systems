#include <stdio.h>
#include <string.h>

// Example 4: Strings and Character Arrays in C
// --------------------------------------------
// In C, strings are arrays of characters ending with a null character '\0'.
// There is no built-in string type like in higher-level languages.
// You use character arrays and functions from <string.h> to manipulate strings.

int main()
{
    char str1[] = "hello"; // Declare and initialize a string (6 bytes: 'h','e','l','l','o','\0')
    char str2[10];         // Declare a character array with space for 10 chars

    // Copy the contents of str1 into str2
    strcpy(str2, str1); // Copies characters including the null terminator

    // Print the copied string
    printf("str2: %s\n", str2);

    // Summary:
    // - Strings are just char arrays ending with '\0'
    // - Use <string.h> functions like strcpy, strlen, strcmp, etc.
    // - Always ensure enough space for the null terminator!
    return 0;
}
