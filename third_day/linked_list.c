//
// Created by Julian Schumacher on 23.10.24.
//

#include <stdio.h>
#include <stdlib.h>

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


void append(struct Element **base, struct Element *new) {
    struct Element *tmp = *base;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->next = nullptr;
}

void appendToList(const struct LinkedList *list, struct Element *new) {
    struct Element *tmp = list->head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->next = nullptr;
}

// TODO: work on (work in progress)
void removeNextElement(struct Element **base, const int id) {
    struct Element *last = nullptr;
    struct Element *tmp = *base;
    while (tmp->id != id) {
        last = tmp;
        tmp = tmp->next;
    }
    last->next = tmp->next;
    free(tmp);
}

void removeElementFromList(struct LinkedList *list, const int id) {
    struct Element *tmp = list->head;
    if (id == tmp->id && tmp->next == nullptr) {
        tmp->next = nullptr;
    } else if (id == tmp->id && tmp->next != nullptr) {
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
}

void printList(const struct LinkedList *list) {
    struct Element *tmp = list->head;
    printf("List:\n");
    do {
        printf("\n");
        printf("Name: %s\n", tmp->name);
        printf("Age: %i\n", tmp->age);
        printf("ID: %i\n", tmp->id);
        tmp = tmp->next;
    } while (tmp != nullptr);
    printf("End of list\n\n");
}

// REMEMBER: Works only outside of function
int counter = 0;

void linked_list() {
    struct LinkedList list;
    struct Element first;
    list.head = &first;
    bool newItem = true;
    struct Element *current;
    const struct Element *last = nullptr;
    while (newItem) {
        current = malloc(sizeof(struct Element));
        printf("Name: ");
        scanf("%s", &current->name);
        printf("Age: ");
        scanf("%i", &current->age);
        current->id = counter;
        counter = counter + 1;
        printf("Counter %i\n", counter);
        current->next = nullptr;
        if (last != nullptr) {
            append(&list.head, current);
        } else {
            list.head = current;
        }
        last = current;
        printf("\nNew Element? ");
        scanf("%d", &newItem);
        printf("\n");
    }
    printList(&list);
    current = list.head;
    printf("Deleting List:\n");
    do {
        removeElementFromList(&list, current->id);
        printList(&list);
        current = current->next;
        counter++;
    } while (current != nullptr);
}
