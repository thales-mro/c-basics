#include <stdio.h>
#include <stdlib.h>

void printSequence(int *seq, int k) {
    int i;

    for(i = 0; i < k; i++) {
        printf("%d", seq[i]);
    }
    printf("\n");
}

void sequences(int *seq, int n, int k, int i) {
    int elem;

    if (i == k) {
        printSequence(seq, k);
        return;
    }

    for(elem = 1; elem <= n; elem++) {
        seq[i] = elem;
        sequences(seq, n, k, i+1);
    }
}

int main() {
    int n, k;
    int *seq;

    printf("Please input two integers, one representing the range of values from 1 to the received input, and the other one for the number of numbers in the sequence: ");
    scanf("%d %d", &n, &k);

    seq = malloc(k * sizeof(int));
    sequences(seq, n, k, 0);

    free(seq);
    return 0;
}