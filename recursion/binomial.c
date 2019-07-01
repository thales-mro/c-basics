#include <stdio.h>

int binomial(int n, int k) {
    if (n == 0 || k == 0 || n == k)
        return 1;
    return binomial(n-1, k-1) + binomial(n-1, k);
}

int main() {
    int n, k;

    printf("Please insert n and k for binomial calculation: ");
    scanf("%d %d", &n, &k);

    printf("The result is %d\n", binomial(n, k));

    return 0;
}