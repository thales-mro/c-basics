#include <stdio.h>
#include <stdlib.h>

void freeMatrixMemory(int **matrix, int n) {
    int i;

    for(i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int m, int n) {
    int i, j;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int ** allocIntMatrix(int m, int n) {
    int **matrix;
    int i, j;

    matrix = malloc(m *sizeof(int *));
    if (matrix == NULL) {
        printf("There are not enough memory!");
        exit(1);
    }
    for(i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("There are not enough memory!");
            exit(1);
        }

        for(j = 0; j < n; j++)
            matrix[i][j] = 0;
    }

    return matrix;
}

int main() {
    int m, n;
    int **matrix;

    printf("Insert the number of rows and columns of int matrix to be alloc: ");
    scanf("%d %d", &m, &n);

    matrix = allocIntMatrix(m, n);
    printMatrix(matrix, m, n);
    freeMatrixMemory(matrix, m);

    printf("Success!\n");

    return 0;
}