//
// Created by Julian Schumacher on 21.10.24.
//

#include "first.h"

double taylorTerm(const double x, const int n) {
    return n == 0 ? 1 : x / n * taylorTerm(x, n - 1);
}

double taylorSeries(const double x, const int count) {
    return count == 0 ? 1 : taylorTerm(x, count - 1) + taylorSeries(x, count - 1);
}
