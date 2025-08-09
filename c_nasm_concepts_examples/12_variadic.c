#include <stdio.h>
#include <stdarg.h>

// Example 12: Variadic Functions in C (like printf)
// -----------------------------------------------
// Variadic functions accept a variable number of arguments.
// Use <stdarg.h> macros: va_list, va_start, va_arg, va_end.

// Print a list of integers, count specifies how many
void print_numbers(int count, ...)
{
    va_list args;          // Declare a variable to access the arguments
    va_start(args, count); // Initialize args to retrieve arguments after 'count'
    for (int i = 0; i < count; i++)
    {
        int n = va_arg(args, int); // Get the next int argument
        printf("%d ", n);
    }
    va_end(args); // Clean up when done
    printf("\n");
}

int main()
{
    // Call print_numbers with 4 arguments after count
    print_numbers(4, 10, 20, 30, 40);

    // Summary:
    // - Variadic functions use ... in the parameter list
    // - Use va_list, va_start, va_arg, va_end to access extra arguments
    // - printf is a classic example of a variadic function
    return 0;
}
