#include <stdio.h>
#include <string.h>

int find_substring(char str[], char substr[]) {
    int str_len = strlen(str);
    int substr_len = strlen(substr);

    if (substr_len == 0) {
        return -1;
    }

    for (int i = 0; i <= str_len - substr_len; i++) {
        int j;
        for (j = 0; j < substr_len; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == substr_len) {
            return i;
        }
    }
    return -1;
}

int main() {
    char str[100], substr[100];

    printf("Enter the original string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;  

    printf("Enter the substring: ");
    fgets(substr, 100, stdin);
    substr[strcspn(substr, "\n")] = 0; 

    int index = find_substring(str, substr);

    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("Substring found at index: -1\n");
    }
    getchar(); 
    getchar();
    return 0;
}