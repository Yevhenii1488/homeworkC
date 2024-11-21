#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "bisection.h"
#define M_PI 3.14159265358979323846

double a_test, b_test;

double test_f(double x) {
    return a_test * sin(x);
}

double test_g(double x) {
    return b_test * cos(x);
}

void test_bisection() {
    double tolerance = 0.00001;

    // Тест 1: a = 1.0, b = 1.0 (корректный)
    a_test = 1.0;
    b_test = 1.0;
    double root1 = bisection(test_f, test_g, 0, M_PI, tolerance);
    printf("Calculated root for test 1: %lf\n", root1);
    assert(fabs(test_f(root1) - test_g(root1)) < tolerance);

    // Тест 2: a = 2.0, b = 1.0 (корректный)
    a_test = 2.0;
    b_test = 1.0;
    double root2 = bisection(test_f, test_g, 0, M_PI, tolerance);
    printf("Calculated root for test 2: %lf\n", root2);
    assert(fabs(test_f(root2) - test_g(root2)) < tolerance);

    // Тест 3: a = 1.0, b = 0.5 (корректный)
    a_test = 1.0;
    b_test = 0.5;
    double root3 = bisection(test_f, test_g, 0, M_PI, tolerance);
    printf("Calculated root for test 3: %lf\n", root3);
    assert(fabs(test_f(root3) - test_g(root3)) < tolerance);

    // Каверзные тесты:
    // Тест 4: a = 0.0, b = 1.0 (некорректный, f(x) = 0 не пересекает g(x) = cos(x))
    a_test = 0.0;
    b_test = 1.0;
    double root4 = bisection(test_f, test_g, 0, M_PI, tolerance);
    printf("Calculated root for test 4 (a = 0): %lf\n", root4);
    assert(fabs(test_f(root4) - test_g(root4)) < tolerance);

    // Тест 5: a = 1.0, b = 0.0 (некорректный, f(x) = sin(x) не пересекает g(x) = 0)
    a_test = 1.0;
    b_test = 0.0;
    double root5 = bisection(test_f, test_g, 0, M_PI, tolerance);
    printf("Calculated root for test 5 (b = 0): %lf\n", root5);
    assert(fabs(test_f(root5) - test_g(root5)) < tolerance);

    // Тест 6: a = -1.0, b = -1.0 (корректный, отрицательные коэффициенты)
    a_test = -1.0;
    b_test = -1.0;
    double root6 = bisection(test_f, test_g, 0, M_PI, tolerance);
    printf("Calculated root for test 6 (negative a and b): %lf\n", root6);
    assert(fabs(test_f(root6) - test_g(root6)) < tolerance);
}

int main() {
    test_bisection();
    printf("All tests completed successfully!\n");
    return 0;
}
