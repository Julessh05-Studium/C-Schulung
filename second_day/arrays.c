//
// Created by Julian Schumacher on 22.10.24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../first_day/first.h"

struct Datensatz {
    double* values;
    int size;
};

struct Matrix {
    double** content;
    int rowCount;
    int colCount;
};

void bubble_sort(const struct Datensatz data) {
    for (int i = 0; i < data.size; ++i) {
        for (int j = 0; j < data.size; ++j) {
            if (data.values[j] > data.values[j + 1]) {
                const double temp = data.values[j];
                data.values[j] = data.values[j + 1];
                data.values[j + 1] = temp;
            }
        }
    }
}

double mittelwert(const struct Datensatz values) {
    double gesamt = 0;
    for (int i = 0; i < values.size; i++) {
        gesamt += values.values[i];
    }
    return gesamt / values.size;
}

double abweichung(const struct Datensatz values) {
    double gesamt = 0;
    const double m = mittelwert(values);
    for (int i = 0; i < values.size; i++) {
        gesamt += pow(values.values[i] - m, 2);
    }
    return sqrt(gesamt/values.size);
}

double array_median(const struct Datensatz values) {
    bubble_sort(values);
    int mid = values.size / 2;
    return values.values[mid];
}

void print_matrix(const struct Matrix m) {
    printf("Die Matrix:\n");
    for (int z = 0; z < m.rowCount; ++z) {
        for (int s = 0; s < m.colCount; ++s) {
            printf("%.2lf ", m.content[z][s]);
        }
        printf("\n\n");
    }
}

struct Matrix get_matrix() {
    printf("Wie groß soll die Matrix werden? (a x b) ");
    int a = 0, b = 0;
    scanf("%i %i", &a, &b);
    struct Matrix m;
    m.rowCount = a;
    m.colCount = b;
    m.content = (double**)malloc(a * sizeof(double*));
    for (int i = 0; i < a; ++i) {
        m.content[i] = (double*)malloc(b * sizeof(double));
    }
    for (int z = 0; z < a; ++z) {
        int zeilennummer = z + 1;
        printf("\nNachfolgend die Daten für Zeile %i:\n", zeilennummer);
        for (int s = 0; s < b; ++s) {
            int spaltennummer = s + 1;
            printf("Zahl eingeben in Zeile %i und Spalte %i ", zeilennummer, spaltennummer);
            double temp;
            scanf("%lf", &temp);
            m.content[z][s] = temp;
        }
    }
    print_matrix(m);
    return m;
}

struct Matrix m_add(const struct Matrix a, const struct Matrix b) {
    struct Matrix r;
    r.rowCount = a.rowCount;
    r.colCount = b.colCount;
    r.content = (double**)malloc(a.rowCount * sizeof(double*));
    for (int i = 0; i < a.rowCount; ++i) {
        r.content[i] = (double*)malloc(a.colCount * sizeof(double));
    }
    for (int z = 0; z < a.rowCount; ++z) {
        for (int s = 0; s < b.colCount; ++s) {
            r.content[z][s] = a.content[z][s] + b.content[z][s];
        }
    }
    return r;
}

struct Matrix m_multiply(const struct Matrix a, const struct Matrix b) {
    struct Matrix r;
    r.rowCount = a.rowCount;
    r.colCount = b.colCount;
    r.rowCount = a.rowCount;
    r.colCount = b.colCount;
    r.content = (double**)malloc(a.rowCount * sizeof(double*));
    for (int i = 0; i < a.rowCount; ++i) {
        r.content[i] = (double*)malloc(a.colCount * sizeof(double));
    }
    for (int z = 0; z < a.rowCount; ++z) {
        for (int s = 0; s < b.colCount; ++s) {
            double result = 0;
            for (int i = 0; i < a.colCount; i++) {
                result += a.content[z][i] * b.content[s][i];
            }
            r.content[z][s] = result;
        }
    }
    return r;
}


int arrays() {
    printf("Wie viele Werte enthält die Messreihe? ");
    int size;
    scanf("%i", &size);
    double* values = malloc(size * sizeof(double));
    if (values == NULL) {
        printf("Error\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < size; i++) {
        printf("Wert eingeben: ");
        scanf("%lf", &values[i]);
    }
    struct Datensatz d;
    d.values = values;
    d.size = size;
    printf("Mittelwert: %.3lf\n", mittelwert(d));
    printf("Abweichung: %.3lf\n", abweichung(d));
    printf("Median: %.3lf\n", array_median(d));
    free(values);

    const struct Matrix a = get_matrix();
    const struct Matrix b = get_matrix();
    if (a.rowCount == b.rowCount && a.colCount == b.colCount) {
        const struct Matrix added = m_add(a, b);
        printf("Addiert:\n");
        print_matrix(added);
        for (int z = 0; z < a.rowCount; ++z) {
            free(added.content[z]);
        }
        free(added.content);
    } else {
        printf("Die Matrizen haben das falsche Format für die Addition\n");
    }
    if (a.rowCount == b.colCount && a.colCount == b.rowCount) {
        const struct Matrix multiplied = m_multiply(a, b);
        printf("Multipliziert:\n");
        print_matrix(multiplied);
        for (int z = 0; z < a.rowCount; ++z) {
            free(multiplied.content[z]);
        }
        free(multiplied.content);
    } else {
        printf("Die Matrizen haben das falsche Format für die Addition\n");
    }
    for (int i = 0; i < a.rowCount; ++i) {
        free(a.content[i]);
    }
    for (int i = 0; i < b.rowCount; ++i) {
        free(b.content[i]);
    }
    free(a.content);
    free(b.content);
    return 0;
}
