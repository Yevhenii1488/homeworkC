#ifndef BISECTION_H
#define BISECTION_H

double bisection(double (*f)(double), double (*g)(double), double a, double b, double tol);

#endif