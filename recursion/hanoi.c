#include <stdio.h>

void hanoi(int n, char origin, char dest, char aux) {
    if (n > 0) {
        hanoi(n - 1, origin, aux, dest);
        printf("move de %c para %c\n", origin, dest);
        hanoi(n - 1, aux, dest, origin);
    }
}

int main() {
    int n;
    
    printf("Please insert the number of hanoi tower pieces: ");
    scanf("%d", &n);

    hanoi(n, 'a', 'c', 'b');
    return 0;
}  