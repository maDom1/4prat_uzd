#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Function to create an empty list
Node* create_empty_list() {
    return NULL;
}

bool value_exists(const Node* head, const char* val) {
    const Node* current = head;
    while (current) {
        if (strcmp(current->data, val) == 0) { // Compare strings
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to insert a new node before a specific value
Node* insert_before_value(Node* head, const char* beforeVal, const char* newVal) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error.\n");
        return head;
    }
    strncpy(newNode->data, newVal, 256);
    newNode->data[255] = '\0';
    newNode->next = NULL;

    // Jei sąrašas tuščias
    if (!head) {
        printf("The list is empty. Adding '%s' as the first element.\n", newVal);
        return newNode; // Pirmasis mazgas tampa sąrašo galva
    }

    // Jei reikia įterpti prieš pirmą mazgą
    if (strcmp(head->data, beforeVal) == 0) {
        newNode->next = head;
        return newNode; // Naujas mazgas tampa sąrašo galva
    }

    Node* current = head;
    while (current->next && strcmp(current->next->data, beforeVal) != 0) {
        current = current->next;
    }

    if (!current->next) {
        printf("Element '%s' not found. Insertion failed.\n", beforeVal);
        free(newNode);
        return head;
    }

    // Įterpti prieš rastą mazgą
    newNode->next = current->next;
    current->next = newNode;

    return head;
}


// Function to print the list recursively
void print_list_recursively(const Node* head) {
    if (!head) return; 
    printf("%s ", head->data); // Print the string
    print_list_recursively(head->next);
}

// Function to clear the list recursively
void clear_list_recursively(Node** head) {
    if (!*head) return;
    clear_list_recursively(&(*head)->next);
    free(*head);
    *head = NULL;
}

// Function to read a list from a file
Node* read_list_from_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file %s.\n", filename);
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;

    char buffer[256];
    while (fscanf(file, "%255s", buffer) == 1) { // Read strings
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
        fprintf(file, "%s ", current->data); // Print strings to file
        current = current->next;
    }
    fprintf(file, "\n");
    fclose(file);
}
