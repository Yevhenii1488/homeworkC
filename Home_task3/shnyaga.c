#include <stdio.h>


void populate_matrix(int size, char matrix[size][size]) {
    char pattern[6] = {'*', '=', '+', '*', '+', '='};
    
    
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            int index = row + col; 
            matrix[row][col] = pattern[index % 6]; 
        }
    }
}


void display_matrix(int size, char matrix[size][size]) {
    
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            printf("%c ", matrix[row][col]);
        }
        printf("\n"); 
    }
}

int main() {
    int dimension;
    
    
    printf("Enter the matrix dimension: ");
    if(scanf("%d", &dimension) != 1) {
        printf("Input error. Please enter a valid number.\n");
        return 1; 
    }

    
    if (dimension <= 0 || dimension > 1000) {
        printf("Matrix size must be between 1 and 1000.\n");
        return 1; 
    }

    char matrix[dimension][dimension];

    populate_matrix(dimension, matrix); 

    display_matrix(dimension, matrix); 
    getchar(); 
    getchar(); 
    return 0;
}
