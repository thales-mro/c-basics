#include <stdio.h>
#include <stdlib.h>

void printDoubleArray(double *a, int n) {
    int i;

    for(i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");
}

double * allocDoubleArray(int n) {
    int i;
    double *v;

    v = malloc(n*sizeof(double));
    if (v == NULL) {
        printf("There are not enough memory");
        exit(1);
    }

    for(i = 0; i < n; i++)
        v[i] = 0.0f;
    
    return v;
}

void freeMemory(double *a) {
    free(a);
}

int main() {
    int n;
    double *array;

    printf("Insert the length of dynamic double array: ");
    scanf("%d", &n);
    array = allocDoubleArray(n);
    printDoubleArray(array, n);

    free(array);
    return 0;
}