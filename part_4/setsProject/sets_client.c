#include <stdio.h>
#include "sets.h"

int main() {
	set a, b, un, it, sub;

	printf("Simulating numeric sets. \"Full\" capacity: 100 elements\n");
	printf("Creating empty set A:\n");
	a = newSet();
	printf("Content of A set: ");
	printSet(a);
	printf("Reading from standard input set B:\n");
	b = readSet();
	printf("Content of B set: ");
	printSet(b);
	printf("Is A set empty? %d\n", isSetEmpty(a));
	printf("Is B set empty? %d\n", isSetEmpty(b));
	printf("Is A set full? %d\n", isSetFull(a));
	printf("Is B set full? %d\n\n", isSetFull(b));

	printf("Inserting elements to A set:\n");
	a = addToSet(a, 10);
	a = addToSet(a, 20);
	printf("Content of A set: ");
	printSet(a);

	if (b.setSize) {
		printf("\nRemoving existing element from B set:\n");
		b = removeFromSet(b, b.elements[0]);
		printf("Content of B set: ");
		printSet(b);
	}
	printf("Removing non-existing element from B set:\n");
	b = removeFromSet(b, 1000);
	printf("Content of B set:");
	printSet(b);

	printf("\nUnion of A and B sets:");
	un = setUnion(a, b);
	printSet(un);
	printf("Intersection of A and B sets:");
	it = setIntersection(a, b);
	printSet(it);
	printf("Subtraction of B set from A set:");
	sub = setSubtraction(a, b);
	printSet(sub);

	return 0;
}
