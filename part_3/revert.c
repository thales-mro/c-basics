#include <stdio.h>
#include <string.h>

#define MAX 100

void revert(char str[]) {
	int n = strlen(str);
	int i;

	for(i = 0; i < n/2; i++) {
		char aux = str[i];
		str[i] = str[n -i -1];
		str[n -i -1] = aux;
	}
}

int main() {
	char str[MAX];
	scanf("%s", str);
	revert(str);
	printf("%s\n", str);

	return 0;
}
