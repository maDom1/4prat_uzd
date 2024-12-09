#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct Node {
    char data[256];
    struct Node* next;
} Node;

Node* create_empty_list();
bool value_exists(const Node* head, const char* val);
Node* insert_before_value(Node* head, const char* beforeVal, const char* newVal);
void print_list_recursively(const Node* head);
void clear_list_recursively(Node** head);
Node* read_list_from_file(const char* filename);
void print_list_to_file(const Node* head, const char* filename);

#endif
