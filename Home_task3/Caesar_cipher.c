#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char encrypt_char(char ch, int key) {
    char base = isupper(ch) ? 'A' : 'a';
    return (ch - base + key + 26) % 26 + base;
}

int main() {
    int numChars, key;

    printf("Enter the number of characters to encrypt: ");
    if (scanf("%d", &numChars) != 1 || numChars < 1) {
        printf("Invalid input!\n");
        return 1;
    }

    srand(time(NULL));
    key = rand() % 513 - 256;
    printf("Generated encryption key: %d\n", key);

    getchar();

    for (int i = 0; i < numChars; i++) {
        char input[10];
        printf("Enter character %d: ", i + 1);
        fgets(input, sizeof(input), stdin);

        if (isalpha(input[0]) && input[1] == '\n') {
            char encrypted = encrypt_char(input[0], key);
            printf("Encrypted character: %c\n", encrypted);
        } else {
            printf("Invalid input: must be a valid alphabetic character\n");            
        }

    }

    return 0;
}
