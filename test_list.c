#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "list.h"

void test_create_empty_list() {
    printf("Test with creating empty list\n");

    Node* list = create_empty_list();
    assert(list == NULL);

    printf("PASSED.\n");
}

void test_insert_before_value() {
    printf("\nTest with inserting in empty list\n");

    Node* list = create_empty_list();
    list = insert_before_value(list, "none", "first");
    assert(list != NULL);
    assert(strcmp(list->data, "first") == 0);
    assert(list->next == NULL);

    printf("PASSED.\n");

    printf("\nTest with inserting in list\n");

    list = insert_before_value(list, "first", "second");
    assert(strcmp(list->data, "second") == 0);
    assert(strcmp(list->next->data, "first") == 0);

    printf("PASSED.\n");
}

void test_clear_list() {
    printf("\nTest with clear list\n");

    Node* list = create_empty_list();
    list = insert_before_value(list, "none", "first");
    list = insert_before_value(list, "first", "second");

    clear_list_recursively(&list);
    assert(list == NULL);

    printf("PASSED.\n");
}

void test_value_exists() {
    printf("\nTest to check if value exists.\n");

    Node* list = create_empty_list();
    list = insert_before_value(list, "none", "first");

    assert(value_exists(list, "first") == true);
    assert(value_exists(list, "none") == false);

    printf("PASSED.\n");
}

int main() {
    test_create_empty_list();
    test_insert_before_value();
    test_clear_list();
    test_value_exists();

    printf("\nAll tests passed successfully.\n");
    return 0;
}
