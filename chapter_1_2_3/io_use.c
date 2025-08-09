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
    FILE *infile;
    FILE *outfile;

    infile = fopen("input.txt", "r"); // relative path name of file, read mode
    if (infile == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }


    // fopen with absolute path of file, write mode
    // Create a file if it does not exist, truncate it if it does
    outfile = fopen("/home/kali/Documents/dive-into-systems/output.txt", "w");
    if (outfile == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        fclose(infile);
        return 1;
    }

    // Read from input file and write to output fileSS
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), infile) != NULL) {
        fprintf(outfile, "%s", buffer);
    }


    // To reset current position to beginning of the file
    rewind(infile);

    // To seek a particular position in the file
    // Seek the beginning of the file
    fseek(infile, 0, SEEK_SET);

    // 3 characters from the beginning of the file
    fseek(infile, 3, SEEK_SET);

    // 3 characters from the end of the file
    fseek(infile, -3, SEEK_END);


    // Other functiions

    // Returns the next character from the file, EOF if no more characters
    int c;
    while ((c = fgetc(infile)) != EOF) {
        // Write the character to the console
        putchar(c);
        // Write the character to the output file
        fputc(c, outfile);
    }

    // Write the character value c to the file stream f
    // returns the char value written, or EOF on error
    fseek(outfile, 0, SEEK_END); // Move to the end of the output file
    fputc('\n', outfile); // Write a newline character
    fputc('A', outfile);

    // Push a chracter back onto the file stream
    // This is not standard C, but some compilers support it
    // ungetc(c, infile);
    
    // Like fgetc and fputc but for stdin and stdout
    // getchar() reads a character from stdin
    // putchar(c) writes a character to stdout

    // Reads at most n-1 characters into the array s stopping if a newline is encountered
    // or if the end of file is reached
    // char *fgets(char *s, int n, FILE *stream);
    char line[100];
    if (fgets(line, sizeof(line), infile) != NULL) {
        printf("Read line: %s", line);
    } else {
        fprintf(stderr, "Error reading line from input file.\n");
    }

    // Read values specified in the format stirng fronm file stream f
    // store the read-in values to program storage locations
    // of types matching the format string
    // int fscanf(FILE *f, const char *format, ...);
    int num1, num2;
    if (fscanf(infile, "%d %d", &num1, &num2) == 2) {
        printf("Read numbers: %d and %d\n", num1, num2);
        fprintf(outfile, "Sum: %d\n", num1 + num2);
    } else {
        fprintf(stderr, "Error reading numbers from input file.\n");
    }   

    // The format string for fscanf can include the following syntax specifying
    // different types of values and ways of reading from the file stream:
    //%d integer
    //%f float
    //%lf double
    //%c character
    //%s string, up to first white space
    //%[...] string, up to first character not in brackets
    //%[0123456789] would read in digits
    //%[^...] string, up to first character in brackets
    //%[^\n] would read everything up to a newline

    fclose(infile);
    fclose(outfile);

    return 0;
}
