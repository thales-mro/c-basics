#include <stdio.h>
#include <string.h>

#define MAX 100

void copy(char str1[], char str2[]) {
	int n = strlen(str1);
	int i;

	for(i = 0; i < n; i++)
		str2[i] = str1[i];
}

int main() {
	char str1[MAX], str2[MAX];
	scanf("%s", str1);
	copy(str1, str2);
	printf("%s\n", str2);

	return 0;
}
