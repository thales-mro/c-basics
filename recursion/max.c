#include <stdio.h>
#include <stdlib.h>

int max(int *a, int n) {
    if (n == 1) {
        return *a;
    } else {
        if (*a > *(a + 1))
            *(a + 1) = *a;
        return max(a + 1, n -1);
    }
}

int main() {
    int n, i, *a;

    printf("Please insert the number of elements to be inserted in the array: ");
    scanf("%d", &n);

    a = malloc(n * sizeof(int));
    if (a == NULL) {
        printf("There are not enough memory!");
        exit(1);
    }

    printf("Please insert the %d array elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if(n > 0)
        printf("The max element in the array is %d\n", max(a, n));
    return 0;
}