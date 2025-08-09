/*
    The Hello World Program in C

    gcc -Wall -g -o hello hello.c
*/

/*
 C math and I/O libraries
*/
#include <math.h>
#include <stdio.h>

/* main function definition */
int main() {


    // gcc -Wall -g -o hello hello.c
    
    int x; // declares x to be an int type variable and allocates space for it
    int i, j, k; // can define multiple variables of the same type like this

    // a char stores a single-byte integer value
    // it is often used to store a single ASCII character
    // value (the ASCII numeric encoding of a character)
    // a char in C is a different type than a string in C
    char letter; 

    float winpct; // winpct is declared to be a float type

    double pi; // the double type is more precise than float


    x = 7; // x stores 7 (initialize variables before using their value)
    k = x + 2; // use x's value in an expression
    letter = 'A'; // a single quote is used for single character value
    letter = letter + 1; // letter stores 'B' (ASCII value one more than 'A')
    pi = 3.1415926;
    winpct = 11 / 2.0; // winpct gets 5.5, winpct is a float type
    j = 11 / 2; // j gets 5: int division truncates after the decimal
    x = k % 2; // % is C's mod operator, so x gets 9 mod 2 (1)

    unsigned int cannot_be_negative = 10000;

    printf("number of bytes in an int: %lu\n", sizeof(int));
    printf("number of bytes in a short: %lu\n", sizeof(short));
    
    return 0;
}
