#include <math.h>
#include "bisection.h"

double bisection(double (*f)(double), double (*g)(double), double a, double b, double tol) {
    double mid;
    int max_iterations = 1000;
    int iterations = 0;

    while ((b - a) / 2.0 > tol && iterations < max_iterations) {
        mid = (a + b) / 2.0;
        if (fabs(f(mid) - g(mid)) < tol) {
            return mid; 
        }
        if ((f(a) - g(a)) * (f(mid) - g(mid)) < 0) {
            b = mid;
        } else {
            a = mid;
        }
        iterations++;
    }

    
    if (fabs(f(mid) - g(mid)) >= tol) {
        return NAN;
    }

    return (a + b) / 2.0;
}