#include <stdio.h>

int main() {
	float beginning, deposit, interest, current;
	int months, i;
	scanf("%f %f %f %d", &beginning, &deposit, &interest, &months);
	current = beginning;
	for(i = 0; i < months; i++) {
		current = current + (current * interest/100);
		current += deposit;
	}

	printf("%f\n", current);

	return 0;
}
