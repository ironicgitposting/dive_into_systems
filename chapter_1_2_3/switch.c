#include <stdio.h>

int main() {
    // Switch example
    int choice;
    printf("Enter a number (1-3): ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            printf("You chose option 1.\n");
            break;
        case 2:
            printf("You chose option 2.\n");
            break;
        case 3: 
            printf("You chose option 3.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}