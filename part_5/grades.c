#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    double *grades, mean;

    printf("Insert the number of grades: ");
    scanf("%d", &n);

    grades = malloc(n * sizeof(double));
    if (grades == NULL) {
        printf("The are not enough memory!");
        exit(1);
    }

    for(i = 0; i < n; i++)
        scanf("%lf", &grades[i]);
    
    mean = 0.0f;
    for(i = 0; i < n; i++)
        mean += grades[i]/n;

    printf("Mean: %.2f\n", mean);
    free(grades);
    return 0;
}