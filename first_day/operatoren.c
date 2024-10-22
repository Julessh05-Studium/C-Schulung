//
// Created by Julian Schumacher on 21.10.24.
//


#include <math.h>
#include <stdio.h>

#include "first.h"

double temperaturberechnen(const double celcius) {
    return celcius + 273;
}

double kreisberechnen(double rad) {
    return 2 * M_PI * rad;
}

double mehrwertsteuer(const double netto) {
    return netto * 0.19;
}

double brutto(const double netto) {
    return netto + mehrwertsteuer(netto);
}

bool boolscherAusdruck(const bool a, const bool b) {
    return a && b || !(a || b) || !(a || b);
}

void operatoren() {
    printf("Radius für den Kreis: ");
    double rad;
    scanf("%lf", &rad);
    printf("Kreisumfang: %.2lf\n", kreisberechnen(rad));

    printf("Temperatur in Celcius: ");
    double c;
    scanf("%lf", &c);
    printf("Temperatur in Kelvin: %.1lf\n", temperaturberechnen(c));

    printf("Nettopreis deines Produktes: ");
    double netto;
    scanf("%lf", &netto);
    printf("Bruttopreis: %.2lf\n", brutto(netto));
    printf("Mehrwertsteuer: %.2lf\n", mehrwertsteuer(netto));

    printf("Wahrheitswert 1 zum testen: ");
    int a;
    scanf("%d", &a);
    printf("Wahrheitswert 2 zum testen: ");
    int b;
    scanf("%d", &b);
    printf("Wahrheitswert: %d", boolscherAusdruck((bool)a, (bool)b));
}
