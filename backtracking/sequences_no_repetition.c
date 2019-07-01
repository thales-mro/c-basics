#include <stdio.h>
#include <stdlib.h>

void printSequence(int *seq, int k) {
    int i;

    for(i = 0; i < k; i++) {
        printf("%d", seq[i]);
    }
    printf("\n");
}

void sequencesNoRepetition(int *seq, int* used, int n, int k, int i) {
    int elem;

    if (i == k) {
        printSequence(seq, k);
        return;
    }

    for(elem = 1; elem <= n; elem++) {
        if (!used[elem]) {
            seq[i] = elem;
            used[elem] = 1;
            sequencesNoRepetition(seq, used, n, k, i+1);
            used[elem] = 0;
        }
    }
}

int main() {
    int n, k;
    int *seq, *used;

    printf("Please input two integers, one representing the range of values from 1 to the received input, and the other one for the number of numbers in the sequence: ");
    scanf("%d %d", &n, &k);

    seq = malloc(k * sizeof(int));
    used = calloc(n + 1, sizeof(int));

    sequencesNoRepetition(seq, used, n, k, 0);

    free(used);
    free(seq);
    return 0;
}