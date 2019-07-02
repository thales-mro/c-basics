#include <stdio.h>
#include <stdlib.h>

int iteractiveBinarySearch(int *v, int n, int element) {
    int l, r, m;
    
    l = 0;
    r = n - 1;

    while(r >= l) {
        m = (l + r)/2;
        if (v[m] == element)
            return m;
        else if (v[m] > element)
            r = m - 1;
        else {
            l = m + 1;
        }
        
    }

    return -1;
}

int main() {
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Finding 2: %d\n", iteractiveBinarySearch(v, 10, 2));
    printf("Finding 9: %d\n", iteractiveBinarySearch(v, 10, 9));
    printf("Finding 1: %d\n", iteractiveBinarySearch(v, 10, 1));
    printf("Finding 10: %d\n", iteractiveBinarySearch(v, 10, 10));
    printf("Finding 11: %d\n", iteractiveBinarySearch(v, 10, 11));

    return 0;
}