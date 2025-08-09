
#include <stdio.h>

/* main function definition */
int main() {
    // C allows generic pointers because
    // memory addresses on a 32-bit system are four bytes long
    // and on a 64-bit system are eight bytes long
    void *gen_ptr;
    int y;
    char ch;

    gen_ptr = &y; // gen_ptr can point to an int
    gen_ptr = &ch; // gen_ptr can also point to a char

    int *array;
    char *str;

    array = (int *)malloc(sizeof(int) * 10); // allocate memory for 10 integers
    str = (char *)malloc(sizeof(char) * 20); // allocate memory for 20 characters

    *array = 42; // assign a value to the first element of the array
    str[0] = 'H'; // assign a character to the first element of the string
    str[1] = 'i';

    free(array); // free the allocated memory
    free(str);

    return 0;
}
