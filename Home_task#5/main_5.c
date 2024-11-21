#include <stdio.h>
#include <math.h>
#include "bisection.h"
#define M_PI 3.14159265358979323846 

double a, b;

double f(double x) {
    return a * sin(x);
}

double g(double x) {
    return b * cos(x);
}

int main() {
    printf("Enter coefficient a: ");
    if (scanf("%lf", &a) != 1) {
        printf("Invalid input for coefficient a.\n");
        return 1;
    }

    printf("Enter coefficient b: ");
    if (scanf("%lf", &b) != 1) {
        printf("Invalid input for coefficient b.\n");
        return 1;
    }

    double result = bisection(f, g, 0, M_PI / 2, 0.0001);

    if (isnan(result)) {
        printf("No intersection found within the given interval.\n");
    } else {
        printf("Intersection at x = %lf\n", result);
    }

    return 0;
}
