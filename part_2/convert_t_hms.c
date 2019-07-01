#include <stdio.h>

int main() {

	int original, hours, minutes, seconds;
	scanf("%ds", &original);

	hours = original / 3600;
	minutes = (original % 3600)/60;
	seconds = (original % 3600)%60;

	printf("%dh%dm%ds\n", hours, minutes, seconds);

	return 0;
}


