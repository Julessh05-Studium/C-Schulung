//
// Created by Julian Schumacher on 21.10.24.
//

#include <stdio.h>

#include "first.h"

double add(const double a, const double b) {
    return a + b;
}

double sub(const double a, const double b) {
    return a - b;
}

double multiply(const double a, const double b) {
    return a * b;
}

double div(const double a, const double b) {
    return a / b;
}

double median(const double a, const double b, const double c) {
    return (a + b + c) / 3;
}

void fibonacci(const int current, const int last) {
    const int next = current + last;
    if (current > 200) {
        return;
    }
    printf("%i, ", current);
    fibonacci(next, current);
}

void methoden() {
    printf("Die beiden Zahlen: ");
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("Summe: %.2lf\n", add(a, b));
    printf("Differenz: %.2lf\n", sub(a, b));
    printf("Produkt: %.2lf\n", multiply(a, b));
    printf("Division: %.2lf\n", div(a, b));

    printf("Die drei Zahlen um den Median zu bilden: ");
    double aa, bb, cc;
    scanf("%lf %lf %lf", &aa, &bb, &cc);
    printf("Median: %.2lf\n", median(aa, bb, cc));
    printf("Fibonacci Zahlenreihe: ");
    fibonacci(1, 0);
}
