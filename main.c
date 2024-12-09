#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "filename.h"

int main() {
    Node* head = NULL;
    bool running = true;

    while (running) {
        printf("\nMenu:\n");
        printf("0 - Create empty list\n");
        printf("1 - Read data from file\n");
        printf("2 - Print list\n");
        printf("3 - Insert a new element before a specified value\n");
        printf("4 - Clear the entire list\n");
        printf("5 - Exit\n");
        printf("Choose: ");

        int choice;
        if (scanf("%d", &choice) != 1 || getchar() != '\n') {
            printf("Invalid input.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 0:
                if (head != NULL) {
                    printf("Warning: A list already exists. Creating an empty list will erase the current list data.\n");
                    printf("Continue? (y/n): ");
                    char confirm;
                    if (scanf(" %c", &confirm) != 1 || getchar() != '\n') {
                        printf("Invalid input.\n");
                        clear_input_buffer();
                        break;
                    }
                    if (confirm == 'y') {
                        clear_list_recursively(&head);
                        head = create_empty_list();
                        printf("Empty list created.\n");
                    } else if (confirm == 'n') {
                        printf("Action canceled.\n");
                    } else {
                        printf("Invalid input. Please enter 'y' or 'n'.\n");
                    }
                } else {
                    head = create_empty_list();
                    printf("Empty list created.\n");
                }
                break;

            case 1: {
                if (head != NULL) {
                    printf("Warning: A list already exists. Reading from file will overwrite the current list.\n");
                    printf("Continue? (y/n): ");
                    char confirm;
                    if (scanf("%c", &confirm) != 1 || getchar() != '\n') {
                        printf("Invalid input. Please enter 'y' or 'n'.\n");
                        clear_input_buffer();
                        break;
                    }

                    if (confirm == 'n') {
                        printf("Action canceled.\n");
                        break;
                    }
                    if(confirm != 'y' && confirm != 'n') {
                        printf("Invalid input. Please enter 'y' or 'n'.\n");
                        break;
                    }
                }

                char *filename = get_valid_filename("Enter the data file name: ");
                if (filename == NULL) {
                    printf("Failed to get a valid file name.\n");
                    break;
                }

                clear_list_recursively(&head);
                head = read_list_from_file(filename);
                if (head != NULL) {
                    printf("Data successfully read from file '%s'.\n", filename);
                } else {
                    printf("Failed to create the list from file. The list is empty.\n");
                }

                free(filename);
                break;
            }

            case 2: {
                if (!head) {
                    printf("The list is empty.\n");
                    break;
                }
                printf("Print to screen (0) or file (1)? ");
                int printChoice;
                if (scanf("%d", &printChoice) != 1 || getchar() != '\n') {
                    printf("Invalid input.\n");
                    clear_input_buffer();
                    break;
                }

                if (printChoice == 0) {
                    printf("List content: ");
                    print_list_recursively(head);
                    printf("\n");
                } else if (printChoice == 1) {
                    char *outFile = get_valid_filename("Enter the output file name: ");
                    if (outFile == NULL) {
                        printf("Failed to get a valid file name.\n");
                        break;
                    }
                    print_list_to_file(head, outFile);
                    printf("List printed to file '%s'.\n", outFile);
                    free(outFile);
                } else {
                    printf("Invalid input. Try again.\n");
                }
                break;
            }

            case 3: {
                char newValue[256];

                if (!head) {
                    printf("The list is empty. Enter the first element's value: ");
                    if (scanf("%255s", newValue) != 1 || getchar() != '\n') {
                        printf("Invalid input.\n");
                        clear_input_buffer();
                        break;
                    }

                    head = insert_before_value(head, "", newValue);
                    printf("Value '%s' added as the first element in the list.\n", newValue);
                    break;
                }

                char beforeValue[256];
                printf("Enter the value before which to insert: ");
                if (scanf("%255s", beforeValue) != 1 || getchar() != '\n') {
                    printf("Invalid input.\n");
                    clear_input_buffer();
                    break;
                }

                if (!value_exists(head, beforeValue)) {
                    printf("Error: Value '%s' not found in the list. Insertion failed.\n", beforeValue);
                    break;
                }

                printf("Enter the new element's value: ");
                if (scanf("%255s", newValue) != 1 || getchar() != '\n') {
                    printf("Invalid input.\n");
                    clear_input_buffer();
                    break;
                }

                head = insert_before_value(head, beforeValue, newValue);
                printf("Value '%s' inserted successfully before '%s'.\n", newValue, beforeValue);
                break;
            }


            case 4:
                if (!head) {
                    printf("The list is already empty.\n");
                } else {
                    printf("Are you sure you want to clear the entire list? (y/n): ");
                    char confirm;
                    if (scanf(" %c", &confirm) != 1 || getchar() != '\n') {
                        printf("Invalid input.\n");
                        clear_input_buffer();
                        break;
                    }
                    if (confirm == 'y' || confirm == 'Y') {
                        clear_list_recursively(&head);
                        printf("The list has been cleared.\n");
                    } else {
                        printf("Action canceled.\n");
                    }
                }
                break;
            case 5:
                printf("Exiting program.\n");
                running = false;
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    clear_list_recursively(&head);
    return 0;
}
