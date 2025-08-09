#include <stdio.h>

int main() {
    int x;
    float pi;

    // read an int value followed by a float value ("%d%g")

    // store the int value at the memory loication of x (&x)
    // store the float value at the memory location of pi (&pi)

    scanf("%d%g", &x, &pi);
    printf("x is: %d\n", x);
    printf("pi is: %g\n", pi);

    char ch = getchar();
    putchar(ch);

    return 0;
}
