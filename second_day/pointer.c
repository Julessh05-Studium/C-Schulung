//
// Created by Julian Schumacher on 22.10.24.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "second.h"

void pointer_actual_sort(int *a, int *b, int *c) {
    int arr[3] = {*a, *b, *c};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    *a = arr[0];
    *b = arr[1];
    *c = arr[2];
}

void pointer_sort() {
    int a = 3;
    int b = 5;
    int c = 2;
    pointer_actual_sort(&a, &b, &c);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
}

void schachbrett() {
    char **schachbrett = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        schachbrett[i] = malloc(sizeof(char) * 8);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bool versetzt = i % 2 == 0;
            if (j % 2 == 0 ^ versetzt) {
                schachbrett[i][j] = '#';
            } else {
                schachbrett[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", schachbrett[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 8; i++) {
        free(schachbrett[i]);
    }
    free(schachbrett);
}

bool isLower(const char ch) {
    return ch >= 'a' && ch <= 'z';
}

bool isUpper(const char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isAlpha(const char ch) {
    return isLower(ch) || isUpper(ch);
}

char toUpper(const char ch) {
    return ch - ('a' - 'A');
}

char toLower(const char ch) {
    return ch + ('a' - 'A');
}

void strInvert(char *text, const int size) {
    for (int i = 0; i < size; i++) {
        if (isAlpha(text[i]) && isUpper(text[i])) {
            text[i] = toLower(text[i]);
        } else if (isLower(text[i]) && isLower(text[i])) {
            text[i] = toUpper(text[i]);
        }
    }
}

void textChange() {
    char text[12] = {'D', 'a', 's', '8', 'H', 'a', 'u', 's', ' ', '!', 's', 't'};
    strInvert(text, 12);
    printf("%s\n", text);
}

bool rechteck(const float *koordinaten, float *ergebnisse) {
    const float seiteA = fabsf(koordinaten[0] - koordinaten[1]);
    const float seiteB = fabsf(koordinaten[2] - koordinaten[3]);
    const float f = seiteA * seiteB;
    const float u = 2 * seiteA + 2 * seiteB;
    ergebnisse[0] = f;
    ergebnisse[1] = u;
    return f != 0;
}

void pointer() {
    pointer_sort();
    schachbrett();
    textChange();
    float koordinaten[4] = {1, 6, 5, 7};
    float ergebnisse[2] = {};
    printf("Rechteck hat F: %d\n", rechteck(&koordinaten, &ergebnisse));
    printf("Rechteck F: %lf, U: %lf", ergebnisse[0], ergebnisse[1]);
}
