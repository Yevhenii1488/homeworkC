#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;

    
    printf("Enter the size of the matrix (N): ");
    if (scanf("%d", &N) != 1 || N <= 0 || N > 100) {
        printf("Invalid matrix size. Please enter a positive number less than or equal to 100.\n");
        return 1;
    }

    int matrix[N][N];

    srand(time(NULL));


    printf("\nMatrix of size %d x %d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(matrix + i) + j) = rand() % 11;
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    int main_diagonal_sum = 0;
    int secondary_diagonal_sum = 0;


    printf("\n--- Diagonal Elements ---\n");
    for (int i = 0; i < N; i++) {
        int main_diag_elem = *(*(matrix + i) + i);
        int sec_diag_elem = *(*(matrix + i) + (N - i - 1));
        
        printf("Main diagonal element [%d][%d]: %d\n", i, i, main_diag_elem);
        printf("Secondary diagonal element [%d][%d]: %d\n", i, N - i - 1, sec_diag_elem);

        main_diagonal_sum += main_diag_elem;
        secondary_diagonal_sum += sec_diag_elem;
    }

    
    printf("\n--- Results ---\n");
    printf("Sum of main diagonal: %d\n", main_diagonal_sum);
    printf("Sum of secondary diagonal: %d\n", secondary_diagonal_sum);

    return 0;
}
