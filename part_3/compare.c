#include <stdio.h>
#include <string.h>

#define MAX 100

int compare(char str1[], char str2[]) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i;

	for(i = 0; i < len1 && i < len2; i++) {
		if (str1[i] > str2[i]) {
			return 1;
		} else if (str1[i] < str2[i]) {
			return -1;
		}
	}

	i++;
	if (str1[i] == '\0' && str2[i] != '\0')
		return -1;
	else if (str2[i] == '\0' && str1[i] != '\0')
		return 1;

	return 0;
}

int main() {
	char str1[MAX], str2[MAX];
	scanf("%s ", str1);
	scanf("%s", str2);
	printf("%d\n", compare(str1, str2));

	return 0;
}
