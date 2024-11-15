#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
    float num;
    printf("Enter a floating-point number: ");
    scanf("%f", &num);

    uint32_t bits = *(uint32_t*)&num;
    int sign = (bits >> 31) & 1;
    int exponent = (bits >> 23) & 0xFF;
    uint32_t mantissa_bits = bits & 0x7FFFFF;
    float mantissa;

    // Проверка на ноль
    if (exponent == 0 && mantissa_bits == 0) {
        printf("Sign bit: %c\n", sign ? '-' : '+');
        printf("Mantissa value: 0.00000\n");
        printf("Exponent value: 0\n");
        printf("Reconstructed value: %c0.0\n", sign ? '-' : '+');
        return 0;
    }

    // Проверка на бесконечность
    if (exponent == 255 && mantissa_bits == 0) {
        printf("Sign bit: %c\n", sign ? '-' : '+');
        printf("Mantissa value: 0.00000\n");
        printf("Exponent value: Inf\n");
        printf("Reconstructed value: %cINFINITY\n", sign ? '-' : '+');
        return 0;
    }

    // Проверка на NaN
    if (exponent == 255 && mantissa_bits != 0) {
        printf("Sign bit: +\n");
        printf("Mantissa value: NaN\n");
        printf("Exponent value: NaN\n");
        printf("Reconstructed value: NaN\n");
        return 0;
    }

    // Обработка нормализованных и денормализованных чисел
    if (exponent != 0) {
        // Нормализованные числа
        exponent -= 127;
        mantissa = 1.0 + mantissa_bits / (float)(1 << 23);
    } else {
        // Денормализованные числа
        exponent = -126;
        mantissa = mantissa_bits / (float)(1 << 23);
    }

    // Восстановление значения
    float reconstructed = (sign ? -1 : 1) * mantissa * powf(2, exponent);

    printf("Sign bit: %c\n", sign ? '-' : '+');
    printf("Mantissa value: %.5f\n", mantissa - (exponent == -126 ? 0 : 1));  // Вывод корректной мантиссы
    printf("Exponent value: %d\n", exponent);
    printf("Reconstructed value: %c%.6f\n", sign ? '-' : '+', reconstructed);

    return 0;
}
