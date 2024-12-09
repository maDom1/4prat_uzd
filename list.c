#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Node* create_empty_list() {
    return NULL;
}

bool value_exists(const Node* head, const char* value) {
    const Node* current = head;
    while (current) {
        if (strcmp(current->data, value) == 0) { 
            return true;
        }
        current = current->next;
    }
    return false;
}

Node* insert_before_value(Node* head, const char* beforeValue, const char* newValue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error.\n");
        return head;
    }
    strncpy(newNode->data, newValue, 256);
    newNode->data[255] = '\0';
    newNode->next = NULL;

    if (!head) {
        printf("The list is empty. Adding '%s' as the first element.\n", newValue);
        return newNode;
    }

    if (strcmp(head->data, beforeValue) == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next && strcmp(current->next->data, beforeValue) != 0) {
        current = current->next;
    }

    if (!current->next) {
        printf("Element '%s' not found. Insertion failed.\n", beforeValue);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void print_list_recursively(const Node* head) {
    if (!head) {
        return; 
    }
    printf("%s ", head->data);
    print_list_recursively(head->next);
}

void clear_list_recursively(Node** head) {
    if (!*head) {
        return;
    }
    clear_list_recursively(&(*head)->next);
    free(*head);
    *head = NULL;
}

Node* read_list_from_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file %s.\n", filename);
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;

    char buffer[256];
    while (fscanf(file, "%255s", buffer) == 1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("Memory allocation error.\n");
            fclose(file);
            clear_list_recursively(&head);
            return NULL;
        }
        strncpy(newNode->data, buffer, 256);
        newNode->data[255] = '\0';
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    fclose(file);
    return head;
}

void print_list_to_file(const Node* head, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open output file.\n");
        return;
    }
    const Node* current = head;
    while (current) {
        fprintf(file, "%s ", current->data);
        current = current->next;
    }
    fprintf(file, "\n");
    fclose(file);
}
