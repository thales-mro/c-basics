#include <stdio.h>
#include <stdlib.h>

void printIntArray(int *a, int n) {
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int countPositive(int *v, int n) {
    int counter, i;

    for(i = 0, counter = 0; i < n; i++) {
        if (v[i] >= 0)
            counter++;
    }

    return counter;
}

void readArrayElements(int *a, int n) {
    int i;

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int *allocIntArray(int n) {
    int *a;

    a = malloc(n * sizeof(int));
    if (a == NULL) {
        printf("There are not enough memory!");
        exit(1);
    }

    return a;
}

int *selectOnlyPositive(int *v, int n, int *nPositive) {
    int *positiveArray;
    int i, j;

    *nPositive = countPositive(v, n);
    positiveArray = allocIntArray(*nPositive);

    j = 0;
    for(i = 0; i < n || j < *nPositive; i++) {
        if(v[i] >= 0)
            positiveArray[j++] = v[i];
    }

    return positiveArray;
}

void freeMemory(int *a) {
    free(a);
}

int main() {
    int n, nPositiveArray;
    int *array, *positiveArray;

    printf("Insert the length of dynamic int array: ");
    scanf("%d", &n);
    array = allocIntArray(n);
    printf("Insert array elements: ");
    readArrayElements(array, n);

    positiveArray = selectOnlyPositive(array, n, &nPositiveArray);
    printIntArray(positiveArray, nPositiveArray);

    freeMemory(array);
    freeMemory(positiveArray);
    return 0;
}