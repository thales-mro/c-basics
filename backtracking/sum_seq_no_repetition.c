#include <stdio.h>
#include <stdlib.h>

void printSequence(int *seq, int n, int c) {
    int i;

    if (n <= 0)
        return;

    printf("%d", seq[0]);
    for (i = 1; i < n; i++) {
        printf(" + %d", seq[i]);
    }

    printf(" = %d\n", c);
}

void sequences(int *seq, int *used, int n, int subC, int c, int i) {
    int elem;

    if (i == n || subC > c) {
        if (subC == c) {
            printSequence(seq, n, c);
        }
        return;
    }

    for (elem = 1; elem <= c; elem++) {
        if (!used[elem]) {
            if (elem + subC <= c) {
                used[elem] = 1;
                seq[i] = elem;
                sequences(seq, used, n, elem + subC, c, i+1);
                used[elem] = 0;
            }
        }
    }
}

int main() {
    int n, c;
    int *seq, *used;

    printf("Please input two integers, representing the number of elements in the sequence and the sum result: ");
    scanf("%d %d", &n, &c);

    seq = malloc(n * sizeof(int));
    used = calloc(c + 1, sizeof(int));
    sequences(seq, used, n, 0, c, 0);

    free(used);
    free(seq);
    return 0;
}