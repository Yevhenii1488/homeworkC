#include <assert.h>
#include <stdio.h>
#include "c_list.h"

void test_c_list() {

    // Створення списку з початковою ємністю 2
    c_list* list = create_list(2);
    
    // Тестування додавання елементів
    int a = 10, b = 20, c = 30;
    list->append(list, &a, int_type);
    list->append(list, &b, int_type); 
    assert(list->size == 2); 

    // Тестування вставки елемента
    list->insert(list, 1, &c, int_type); 
    assert(*(int*)list->items[1] == 30); 

    // Тестування пошуку індексу
    int index = list->find_index(list, &b, int_type); 
    assert(index == 2); 

    // Тестування видалення останнього елемента
    list->pop(list); 
    assert(list->size == 2); 

    // Звільнення пам'яті списку
    list->destroy(list); 

    printf("All tests passed!\n");
}

int main() {
    test_c_list();
    return 0;
}
