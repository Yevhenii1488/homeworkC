#include <stdio.h>

void printBinary(int n) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main() {
    int value, key, encrypted, decrypted, verboseMode;

    printf("Enter a value: ");
    scanf("%d", &value);
    printf("Enter a key (number for XOR): ");
    scanf("%d", &key);
    printf("Activate verbose mode? (1 for Yes, 0 for No): ");
    scanf("%d", &verboseMode);

    if (verboseMode != 0 && verboseMode != 1) {
        printf("Invalid input for verbose mode. Please enter 1 for Yes or 0 for No.\n");
        return 1;
    }

    printf("Original value (Decimal): %d\n", value);
    if (verboseMode) {
        printf("Binary: ");
        printBinary(value);
    }

    encrypted = value ^ key;
    printf("Encrypted value (Decimal): %d\n", encrypted);
    if (verboseMode) {
        printf("Binary: ");
        printBinary(encrypted);
    }

    decrypted = encrypted ^ key;
    printf("Decrypted value (Original): %d\n", decrypted);
    if (verboseMode) {
        printf("Binary: ");
        printBinary(decrypted);
    }

    return 0;
}
