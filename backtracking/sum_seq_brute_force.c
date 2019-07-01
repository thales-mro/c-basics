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

void sequences(int *seq, int n, int subC, int c, int i) {
    int elem;

    if (i == n || subC > c) {
        if (subC == c) {
            printSequence(seq, n, c);
        }
        return;
    }

    for (elem = 1; elem <= c; elem++) {
        if (elem + subC <= c) {
            seq[i] = elem;
            sequences(seq, n, elem + subC, c, i+1);
        }
    }
}

int main() {
    int n, c;
    int *seq;

    printf("Please input two integers, representing the number of elements in the sequence and the sum result: ");
    scanf("%d %d", &n, &c);

    seq = malloc(n * sizeof(int));
    sequences(seq, n, 0, c, 0);

    free(seq);
    return 0;
}