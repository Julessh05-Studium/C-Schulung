//
// Created by Julian Schumacher on 21.10.24.
//

#include <stdio.h>

#include "first.h"

double zins(double betrag, const double zinssatz, const int dauer) {
    for (int i = 0; i <= dauer; i++) {
        betrag = betrag + betrag * zinssatz;
    }
    return betrag;
}

void oneOone() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%i ", i * j);
        }
        printf("\n");
    }
}

double archimedes(int zahl, int n) {
    double result;

    return result;
}


void zahlenAuflisten(const int zahl, const bool gerade) {
    int i;
    if (gerade) {
        i = 0;
    } else {
        i = 1;
    }
    for (; i <= zahl; i = i + 2) {
        printf("%i, ", i);
    }
}

void zahlenreihe(const int steps) {
    for (int i = steps; i < 100; i = i + steps) {
        printf("%i, ", i);
    }
}

int summieren(const int max) {
    int result = 0;
    for (int i = 1; i <= max; i++) {
        result += i;
    }
    return result;
}

double potenzieren(const double a, const int b) {
    double result = 0;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
    // ODER: return math.pow(a, b);
}

double fakult(const int zahl) {
    double result = 0;
    for (int i = 1; i < zahl; i++) {
        result *= i;
    }
    return result;
}

int medianFinden(
    const int a,
    const int b,
    const int c,
    const int d,
    const int e
) {
    int arr[5] = {a, b, c, d, e};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr[2];
}


void schleifen() {
    printf("Anzulegender Geldbetrag: ");
    double betrag;
    scanf("%lf", &betrag);
    printf("Zinssatz: ");
    double zinssatz;
    scanf("%lf", &zinssatz);
    printf("Laufzeit (Jahre): ");
    int laufzeit;
    scanf("%i", &laufzeit);
    const double endkapital = zins(betrag, zinssatz, laufzeit);
    printf("Endkapital: %lf, davon Zinsen: %lf\n", endkapital, endkapital - betrag);

    oneOone();

    printf("Bitte Zahl eingeben: ");
    int zahlZumAuflisten;
    scanf("%i", &zahlZumAuflisten);
    printf("Gerade oder ungerade (g oder u)?");
    char gOu;
    scanf("%c", &gOu);
    zahlenAuflisten(zahlZumAuflisten, gOu == 'g');

    printf("Bitte Zahl eingeben: ");
    int zahlenReihenSteps;
    scanf("%i", &zahlenReihenSteps);
    zahlenreihe(zahlenReihenSteps);

    printf("Bitte Zahl zum Summieren eingeben: ");
    int zahlZumSummieren;
    scanf("%i", &zahlZumSummieren);
    printf("%i", summieren(zahlZumSummieren));

    printf("Zahl zum potenzieren eingeben: ");
    int zahlZumPotenzieren;
    scanf("%i", &zahlZumPotenzieren);
    printf("Potenz eingeben: ");
    int potenz;
    scanf("%i", &potenz);
    printf("%lf", potenzieren(zahlZumPotenzieren, potenz));

    printf("Zahl für Fakultät: ");
    double fakult;
    scanf("%lf", &fakult);
    printf("Fakultät: %lf", fakult);

    printf("Zahlen für Median ");
    int medianZahla, medianZahlb, medianZahlc, medianZahld, medianZahle;
    scanf("%i, %i, %i, %i, %i", &medianZahla, &medianZahlb, &medianZahlc, &medianZahld, &medianZahle);
    printf("Der Median ist %i", medianFinden(medianZahla, medianZahlb, medianZahlc, medianZahlc, medianZahle));
}
