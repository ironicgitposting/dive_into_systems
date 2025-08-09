/*
    C Program: Using Command-Line Arguments
    Compile: gcc -Wall -g -o args_example args_example.c
    Run: ./args_example arg1 arg2 ...
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
}

/*
Explanation:
- argc: Number of command-line arguments (including program name)
- argv: Array of strings (char pointers), each string is one argument
- argv[0]: Program name
- argv[1] ... argv[argc-1]: User-supplied arguments
*/
