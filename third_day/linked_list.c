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


void append(struct Element *base, struct Element *new) {
    struct Element *tmp = base;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->next = nullptr;
}

void linked_list() {
    struct LinkedList list;
    struct Element first;
    list.head = &first;
    int counter = 0;
    bool newItem = true;
    struct Element *current;
    struct Element *last = nullptr;
    while (newItem) {
        current = malloc(sizeof(struct Element));
        printf("Name: ");
        scanf("%s", &current->name);
        printf("Age: ");
        scanf("%i", &current->age);
        current->id = counter++;
        current->next = nullptr;
        if (last != nullptr) {
            append(last, current);
        } else {
            list.head = current;
        }
        last = current;
        printf("\nNew Element? ");
        scanf("%d", &newItem);
    }
    current = list.head;
    printf("List:\n");
    do {
        printf("Name: %s\n", current->name);
        printf("Age: %i\n", current->age);
        printf("ID: %i\n\n", current->id);
        current = current->next;
    } while (current != nullptr);
    printf("End of list");
    current = list.head;
    do {
        current = current->next;
        free(current->next);
    } while (current != nullptr);
}
