#include <stdio.h>
#include <stdlib.h>

double *** alloc3DDoubleMatrix(int m, int n, int o) {
    int i, j, k;
    double ***matrix;

    matrix = malloc(m * sizeof(double **));
    if(matrix == NULL) {
        printf("There are not enough memory!");
        exit(1);
    }

    for(i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(double *));
        if(matrix[i] == NULL) {
            printf("There are not enough memory!");
            exit(1);
        }

        for(j = 0; j < n; j++) {
            matrix[i][j] = malloc(o * sizeof(double));
            if(matrix[i][j] == NULL) {
                printf("There are not enough memory!");
                exit(1);
            }

            for(k = 0; k < o; k++) {
                matrix[i][j][k] = 0.0f;
            }
        }
    }

    return matrix;
}

void free3DMatrixMemory(double ***matrix, int m, int n) {
    int i, j;
    
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int m, n, o;
    double ***matrix;

    printf("Insert the length of dimensions of 3D matrix: ");
    scanf("%d %d %d", &m, &n, &o);
    matrix = alloc3DDoubleMatrix(m, n, o);

    free3DMatrixMemory(matrix, m, n);
    return 0;
}