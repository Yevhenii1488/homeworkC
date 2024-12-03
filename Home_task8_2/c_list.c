#include "c_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Створення нового списку
c_list* create_list(size_t initial_capacity) {
    c_list* list = malloc(sizeof(c_list));
    if (!list) {
        fprintf(stderr, "Помилка: не вдалося виділити пам'ять для списку.\n");
        exit(EXIT_FAILURE);
    }

    list->items = calloc(initial_capacity, sizeof(void*));
    list->types = calloc(initial_capacity, sizeof(list_data_type));
    if (!list->items || !list->types) {
        fprintf(stderr, "Помилка: не вдалося виділити пам'ять для елементів списку.\n");
        free(list);
        exit(EXIT_FAILURE);
    }

    list->size = 0;
    list->capacity = initial_capacity;

    // Призначення функцій
    list->append = append;
    list->pop = pop;
    list->destroy = destroy;
    list->print = print;
    list->find_index = find_index;
    list->insert = insert;

    return list;
}

// Додавання нового елемента до списку
void append(c_list* list, void* item, list_data_type type) {
    if (list->size >= list->capacity) {
        // Розширення масиву, якщо не вистачає ємності
        list->capacity *= 2;
        list->items = realloc(list->items, list->capacity * sizeof(void*));
        list->types = realloc(list->types, list->capacity * sizeof(list_data_type));
        if (!list->items || !list->types) {
            fprintf(stderr, "Помилка: не вдалося змінити розмір масиву.\n");
            exit(EXIT_FAILURE);
        }
    }

    void* new_item = NULL;
    // Створення копії елемента залежно від його типу
    switch (type) {
        case int_type:
            new_item = malloc(sizeof(int));
            memcpy(new_item, item, sizeof(int));
            break;
        case float_type:
            new_item = malloc(sizeof(float));
            memcpy(new_item, item, sizeof(float));
            break;
        case string_type:
            new_item = malloc(strlen((char*)item) + 1);
            strcpy(new_item, item);
            break;
    }

    if (!new_item) {
        fprintf(stderr, "Помилка: не вдалося виділити пам'ять для нового елемента.\n");
        exit(EXIT_FAILURE);
    }

    list->items[list->size] = new_item;
    list->types[list->size] = type;
    list->size++;
}

// Видалення останнього елемента зі списку
void pop(c_list* list) {
    if (list->size > 0) {
        free(list->items[list->size - 1]); // Звільнення пам'яті для останнього елемента
        list->size--;
    }
}

// Звільнення всієї пам'яті, що використовується списком
void destroy(c_list* list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->items[i]); // Звільнення пам'яті для кожного елемента
    }
    free(list->items);
    free(list->types);
    free(list);
}

// Виведення вмісту списку
void print(const c_list* list) {
    for (size_t i = 0; i < list->size; i++) {
        switch (list->types[i]) {
            case int_type:
                printf("%d ", *(int*)list->items[i]);
                break;
            case float_type:
                printf("%f ", *(float*)list->items[i]);
                break;
            case string_type:
                printf("%s ", (char*)list->items[i]);
                break;
        }
    }
    printf("\n");
}

// Пошук індексу елемента в списку
int find_index(const c_list* list, void* item, list_data_type type) {
    for (size_t i = 0; i < list->size; i++) {
        if (list->types[i] == type) {
            if (type == int_type && *(int*)list->items[i] == *(int*)item) {
                return i;
            } else if (type == float_type && *(float*)list->items[i] == *(float*)item) {
                return i;
            } else if (type == string_type && strcmp((char*)list->items[i], (char*)item) == 0) {
                return i;
            }
        }
    }
    return -1; // Елемент не знайдено
}

// Вставка елемента у визначену позицію
void insert(c_list* list, size_t pos, void* item, list_data_type type) {
    if (pos > list->size) return; // Перевірка валідності позиції

    if (list->size >= list->capacity) {
        // Розширення масиву, якщо не вистачає ємності
        list->capacity *= 2;
        list->items = realloc(list->items, list->capacity * sizeof(void*));
        list->types = realloc(list->types, list->capacity * sizeof(list_data_type));
        if (!list->items || !list->types) {
            fprintf(stderr, "Помилка: не вдалося змінити розмір масиву.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Зсув елементів для вставки нового
    for (size_t i = list->size; i > pos; i--) {
        list->items[i] = list->items[i - 1];
        list->types[i] = list->types[i - 1];
    }

    void* new_item = NULL;
    // Створення копії елемента залежно від його типу
    switch (type) {
        case int_type:
            new_item = malloc(sizeof(int));
            memcpy(new_item, item, sizeof(int));
            break;
        case float_type:
            new_item = malloc(sizeof(float));
            memcpy(new_item, item, sizeof(float));
            break;
        case string_type:
            new_item = malloc(strlen((char*)item) + 1);
            strcpy(new_item, item);
            break;
    }

    if (!new_item) {
        fprintf(stderr, "Помилка: не вдалося виділити пам'ять для нового елемента.\n");
        exit(EXIT_FAILURE);
    }

    list->items[pos] = new_item;
    list->types[pos] = type;
    list->size++;
}
