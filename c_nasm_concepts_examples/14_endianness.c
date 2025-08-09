#include <stdio.h>

// Example 14: Endianness Check in C
// ---------------------------------
// Endianness refers to the order in which bytes are stored in memory.
// Little endian: least significant byte is stored first (at lowest address)
// Big endian: most significant byte is stored first

int main()
{
    unsigned int x = 0x12345678; // 4-byte integer with known pattern
    // Cast the address of x to a pointer to unsigned char (byte)
    unsigned char *c = (unsigned char *)&x;

    // Print the value of the first byte in memory
    printf("First byte: 0x%x\n", c[0]);

    // If the first byte is 0x78, the system is little endian
    if (c[0] == 0x78)
        printf("Little endian\n");
    else
        printf("Big endian\n");

    // Summary:
    // - Endianness matters for binary data, networking, and low-level code
    // - This trick lets you check endianness at runtime
    return 0;
}
