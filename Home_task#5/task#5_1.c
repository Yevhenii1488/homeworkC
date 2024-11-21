#include <stdio.h>
#include <math.h>

double newton_raphson_sqrt(double number, double initial_guess, double tolerance, int *iterations) {
    double guess = initial_guess;
    double previous_guess;
    *iterations = 0;

    do {
        previous_guess = guess;
        guess = (guess + number / guess) / 2.0;
        (*iterations)++;
    } while (fabs(guess - previous_guess) > tolerance);

    return guess;
}

int main() {
    double number, initial_guess, tolerance, result;
    int iterations;

    printf("Enter the number to find the square root of: ");
    scanf("%lf", &number);
    printf("Enter the initial guess for the root: ");
    scanf("%lf", &initial_guess);
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    if (number <= 0) {
        printf("Error: Please enter a positive number for the square root calculation.\n");
        return 1;
    }

    if (initial_guess <= 0) {
        printf("Warning: Initial guess should be positive. Using default value 1.0.\n");
        initial_guess = 1.0;
    }

    if (tolerance <= 0) {
        printf("Error: Please enter a positive tolerance for convergence.\n");
        return 1;
    }

    result = newton_raphson_sqrt(number, initial_guess, tolerance, &iterations);

    printf("Number of iterations: %d\n", iterations);
    printf("Approximate square root: %.6lf\n", result);

    return 0;
}
