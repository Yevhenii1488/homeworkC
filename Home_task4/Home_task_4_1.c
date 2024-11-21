#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void fill_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix[N][N];
    srand(time(NULL));

    printf("Original Matrix:\n");
    fill_matrix(matrix);
    print_matrix(matrix);

    transpose_matrix(matrix);
    printf("\nTransposed Matrix:\n");
    print_matrix(matrix);

    return 0;
}
