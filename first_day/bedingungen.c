//
// Created by Julian Schumacher on 21.10.24.
//

#include <stdio.h>

#include "first.h"

bool februarTage(const int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

double cmInch(const double input, const char type) {
    const double f = 2.54;
    return type == 'c' ? input / f : input * f;
}

// TODO: update sort
void sort(const int inputArr[3], int *sortedArr) {
    for (int i = 0; i < 3; i++) {
        sortedArr[i] = inputArr[i];
    }
    for (int i = 0; i < 3; i = i + 2) {
        if (inputArr[i] > inputArr[i + 1]) {
            sortedArr[i + 1] = inputArr[i];
            sortedArr[i] = inputArr[i + 1];
        }
    }
}

int bedingungen() {
    printf("Jahr: ");
    int y;
    scanf("%d", &y);
    printf("Der Februar hat %d Tage\n", februarTage(y) ? 29 : 28);

    printf("input (zahl (i/c): ");
    double input;
    char type;
    scanf("%lf %c", &input, &type);
    if (!(type == 'c' || type == 'i')) {
        printf("Fehlerhafte Eingabe");
        return 1;
    }
    printf("%.2f %s\n", cmInch(input, type), type == 'c' ? "inch" : "cm");

    printf("Drei Zahlen zum Sortieren: ");
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    const int arr[3] = {a, b, c};
    int arrSorted[3];
    sort(arr, &arrSorted);
    printf("Sortiert: %i, %i, %i", arrSorted[0], arrSorted[1], arrSorted[2]);
    return 0;
}
