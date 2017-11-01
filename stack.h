typedef double stackContents;

struct element
{
	double contents;
	int stackSize;	
	struct element *next;
};

int size(struct element* listHead);
struct element* push(struct element* oldHead, double data);
double pop(struct element** headPointer);
