#include <stdio.h>

// Example 10: Storage Classes in C
// --------------------------------
// Storage classes (auto, static, extern, register) control variable lifetime and visibility.
// 'static' inside a function means the variable retains its value between calls.

void foo()
{
    static int count = 0; // static: value persists across function calls
    count++;              // Increment count each time foo() is called
    printf("count = %d\n", count);
}

int main()
{
    // Call foo() three times; count will keep its value between calls
    for (int i = 0; i < 3; i++)
        foo();

    // Output:
    // count = 1
    // count = 2
    // count = 3

    // Summary:
    // - static variables inside functions keep their value between calls
    // - Useful for counters, caching, and persistent state
    return 0;
}
