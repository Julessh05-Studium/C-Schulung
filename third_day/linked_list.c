//
// Created by Julian Schumacher on 23.10.24.
//

#include <stdio.h>
#include <stdlib.h>

#include "third.h"

void linked_list() {
    int size;
    printf("Enter the size of the text: ");
    scanf("%d", &size);
    char *ptr = malloc(size * sizeof(char));
    printf("Enter your text: ");
    scanf("%s", ptr);
    printf("Your text is: %s", ptr);
    free(ptr);
}
