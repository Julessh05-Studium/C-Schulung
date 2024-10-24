//
// Created by Julian Schumacher on 23.10.24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "third.h"

/* DYNAMIC ARRAY */

void dynamicArray() {
    int size;
    printf("Enter the size of the text: ");
    scanf("%d", &size);
    char *ptr = malloc(size * sizeof(char));
    printf("Enter your text: ");
    scanf("%s", ptr);
    printf("Your text is: %s", ptr);
    free(ptr);
}

/* LINKED LIST */

struct Element {
    char name[50];
    int age;
    int id;
    struct Element *next;
};

struct LinkedList {
    struct Element *head;
    int length;
};

void appendToList(struct LinkedList *list, struct Element *new) {
    struct Element *tmp = list->head;
    if (tmp == nullptr) {
        list->head = new;
    } else {
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new;
        new->next = nullptr;
    }
    list->length++;
}

void removeElementFromList(struct LinkedList *list, const int id) {
    struct Element *tmp = list->head;
    if (tmp->next == nullptr) {
        if (id == tmp->id) {
            list->head = nullptr;
        }
        // only one element, not same id, return from func
    } else if (id == tmp->id) {
        list->head = tmp->next;
    } else {
        struct Element *last = nullptr;
        while (tmp->id != id) {
            if (tmp->next == nullptr) {
                // ID not found in list
                return;
            }
            last = tmp;
            tmp = tmp->next;
        }
        last->next = tmp->next;
    }
    list->length--;
}

void printList(const struct LinkedList *list) {
    if (list->head == nullptr) {
        // list is empty
        printf("List is empty\n");
        return;
    }
    struct Element *tmp = list->head;
    printf("============================================================\n");
    printf("List:\n");
    do {
        printf("\n");
        printf("Name: %s\n", tmp->name);
        printf("Age: %i\n", tmp->age);
        printf("ID: %i\n", tmp->id);
        tmp = tmp->next;
    } while (tmp != nullptr);
    printf("\nEnd of list\n\n");
    printf("============================================================\n");
}

/// Inserts an element into the list, at the given position and updates the following index
void insertIntoList(struct LinkedList *list, struct Element *new, const int position) {
    struct Element *tmp = list->head;
    if (tmp->id == position) {
        // Position is 0
        new->next = tmp->next;
        list->head = new;
    } else {
        while (tmp->id != position - 1) {
            if (tmp->next == nullptr) {
                // ID out of bound of list
                return;
            }
            tmp = tmp->next;
        }
        new->next = tmp->next;
        tmp->next = new;
    }
    new->id = position;
    tmp = new->next;
    do {
        tmp->id++;
        tmp = tmp->next;
    } while (tmp != nullptr);
    list->length++;
}

/// Sorts the List alphabetically
void sortList(struct LinkedList *list) {
    // only used to keep outer iteration running
    const struct Element *current_outer = list->head;
    struct Element *current_inner = list->head;
    struct Element *last = nullptr;
    // If head is only element, loop not entered => list already sorted
    while (current_outer->next != nullptr) {
        while (current_inner != nullptr) {
            if (strcmp(current_inner->name, current_inner->next->name) != 0) {
                struct Element *next = current_inner->next;
                if (last == nullptr) {
                    struct Element *old_head = list->head;
                    list->head = next;
                    old_head->next = next->next;
                    next->next = current_inner;
                } else {
                    last->next = next;
                    current_inner->next = next->next;
                    next->next = current_inner;
                }
            }
            last = current_inner;
            current_inner = current_inner->next;
        }
        current_outer = current_outer->next;
    }
}

// REMEMBER: Works only outside of function
int id_counter = 0;

void linked_list() {
    // Creating List
    struct LinkedList list;
    list.length = 0;
    list.head = nullptr;
    int newItem = 1;
    struct Element *current;
    // filling list / adding elements
    while (newItem) {
        current = malloc(sizeof(struct Element));
        printf("Name: ");
        scanf("%s", &current->name);
        printf("Age: ");
        scanf("%i", &current->age);
        current->id = id_counter++;
        current->next = nullptr;
        if (list.head == nullptr) {
            list.head = current;
        } else {
            appendToList(&list, current);
        }
        printf("\nNew Element? ");
        scanf("%d", &newItem);
        printf("\n");
    }
    printList(&list);

    // Inserting element
    /*
    printf("Element to add:\n");
    current = malloc(sizeof(struct Element));
    printf("Name: ");
    scanf("%s", &current->name);
    printf("Age: ");
    scanf("%i", &current->age);
    current->id = id_counter++;
    current->next = nullptr;
    printf("place to insert: ");
    int insert_at = 0;
    scanf("%d", &insert_at);
    insertIntoList(&list, current, insert_at);
    printf("\n");
    printf("List with inserted element:\n");
    printList(&list);
    printf("\n");
    */

    // Sorting List alphabetically
    sortList(&list);
    printf("Sorted List:\n");
    printList(&list);

    // Deleting list
    current = list.head;
    printf("Deleting List:\n");
    do {
        removeElementFromList(&list, current->id);
        printList(&list);
        current = current->next;
    } while (current != nullptr);
}
