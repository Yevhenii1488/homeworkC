#include "c_list.h"
#include <stdio.h>
#include <string.h>

int append_list_item(void* list[], list_data_type types[], int size, void* item, list_data_type type) {
    if (size >= CAPACITY) {
        return -1;
    }
    list[size] = item;
    types[size] = type;
    return size + 1;
}

void print_list(const void* list[], const list_data_type types[], int size) {
    for (int i = 0; i < size; i++) {
        switch (types[i]) {
            case int_type:
                printf("%d ", *(int*)list[i]);
                break;
            case float_type:
                printf("%f ", *(float*)list[i]);
                break;
            case string_type:
                printf("%s ", (char*)list[i]);
                break;
        }
    }
    printf("\n");
}
