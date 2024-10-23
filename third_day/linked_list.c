//
// Created by Julian Schumacher on 23.10.24.
//

#include <stdio.h>
#include <stdlib.h>

#include "third.h"

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


void append(struct Element **base, struct Element *new) {
    struct Element *tmp = *base;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->next = nullptr;
}

void removeElementFromList(struct Element **base, int id) {
    struct Element *last = nullptr;
    struct Element *tmp = *base;
    while (tmp->id != id) {
        last = tmp;
        tmp = tmp->next;
    }
    last->next = tmp->next;
    free(tmp);
}

void printList(struct Element **base) {
    struct Element *tmp = *base;
    printf("List:\n");
    do {
        printf("Name: %s\n", tmp->name);
        printf("Age: %i\n", tmp->age);
        printf("ID: %i\n\n", tmp->id);
        tmp = tmp->next;
    } while (tmp != nullptr);
    printf("End of list\n\n");
}

void linked_list() {
    struct LinkedList list;
    struct Element first;
    list.head = &first;
    int counter = 0;
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
    current = list.head;
    printList(&current);
    current = list.head;
    printf("Deleting List:\n");
    do {
        removeElementFromList(&list.head, current->id);
        printList(&current);
        free(current->next);
        current = current->next;
    } while (current != nullptr);
}
