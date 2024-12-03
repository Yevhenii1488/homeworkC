#ifndef C_LIST_H
#define C_LIST_H

#include <stddef.h> // Для size_t


typedef enum {
    int_type,  
    float_type, 
    string_type
} list_data_type;

// Основна структура списку
typedef struct c_list {
    void** items;               // Динамічний масив вказівників на елементи
    list_data_type* types;      // Масив типів даних для кожного елемента
    size_t size;                // Поточна кількість елементів у списку
    size_t capacity;            // Поточна ємність списку

    // Вказівники на функції для операцій зі списком
    void (*append)(struct c_list* list, void* item, list_data_type type); // Додати елемент
    void (*pop)(struct c_list* list);                                    // Видалити останній елемент
    void (*destroy)(struct c_list* list);                                // Звільнити пам'ять для списку
    void (*print)(const struct c_list* list);                            // Вивести вміст списку
    int (*find_index)(const struct c_list* list, void* item, list_data_type type); // Знайти індекс елемента
    void (*insert)(struct c_list* list, size_t pos, void* item, list_data_type type); // Вставити елемент
} c_list;

// Оголошення функцій для роботи зі списком

c_list* create_list(size_t initial_capacity);
void append(c_list* list, void* item, list_data_type type);
void pop(c_list* list);
void destroy(c_list* list);
void print(const c_list* list);
int find_index(const c_list* list, void* item, list_data_type type);
void insert(c_list* list, size_t pos, void* item, list_data_type type);

#endif // C_LIST_H
