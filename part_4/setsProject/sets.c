#include "sets.h"
#include <stdio.h>

void printSet(set a) {
	int i;
	for(i = 0; i < a.setSize; i++) {
		printf("%d ", a.elements[i]);
	}
	printf("\n");
}

set newSet() {
	set s;
	s.setSize = 0;
	return s;
}

set readSet() {
	set s = newSet();
	int size, i;

	printf("Type the set length to be received: ");	
	scanf("%d", &size);
	if (size < 0)
		size = 0;
	else if (size > 100)
		size = 100;
	s.setSize = size;

	for(i = 0; i < size; i++) {
		scanf("%d", &s.elements[i]);
	}		

	return s;
}

int isSetEmpty(set a) {
	if (a.setSize <= 0)
		return 1;
	return 0;
}

int isSetFull(set a) {
	if (a.setSize >= 100)
		return 1;
	return 0;
}

set addToSet(set a, int element) {
	if (!isSetFull(a)) {
		a.elements[a.setSize] = element;
		a.setSize++;
	}

	return a;
}

int inSetPos(set a, int element) {
	int i;
	for(i = 0; i < a.setSize; i++)
		if (a.elements[i] == element)
			return i;

	return -1;
}

set moveLeft(set a, int pos) {
	int i;
	for(i = pos; i < a.setSize - 1; i++)
		a.elements[i] = a.elements[i + 1];
	return a;
}

set removeFromSet(set a, int element) {
	int pos = inSetPos(a, element);
	if (pos != -1) {
		a = moveLeft(a, pos);
		a.setSize--;
	}
	return a;
}

set setUnion(set a, set b) {
	int i;
	for(i = 0; i < b.setSize; i++) 
		if (inSetPos(a, b.elements[i]) == -1) 
			a = addToSet(a, b.elements[i]);
	return a;
}

set setIntersection(set a, set b) {
	set c = newSet();
	int i;

	for(i = 0; i < a.setSize; i++) {
		if(inSetPos(b, a.elements[i]) > -1)
			c = addToSet(c, a.elements[i]);
	}

	return c;
}

set setSubtraction(set a, set b) {
	int i, pos;
	
	for(i = 0; i < b.setSize; i++) {
		pos = inSetPos(a, b.elements[i]);
		if (pos > -1) {
			a = moveLeft(a, pos);
			a.setSize--;
		}
	}

	return a;
}
