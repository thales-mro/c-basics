#define MAX 100

typedef struct {
	int setSize;
	int elements[MAX];	
}set;

set readSet();

set newSet();

int isSetEmpty(set a);

int isSetFull(set a);

void printSet(set a);

set addToSet(set a, int element);

set removeFromSet(set a, int element);

set setUnion(set a, set b);

set setIntersection(set a, set b);

set setSubtraction(set a, set b);

int inSetPos(set a, int element);
