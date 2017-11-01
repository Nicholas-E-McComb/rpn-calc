#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int size(struct element* head){
	return head->stackSize;
}



/* Takes the current head of the stack and some input (as a double).  Creates a new 
 * stack element structure, with its contents as the input and its "next" element as the
 * previous head element, then switches the "head" pointer to itself.
 *
 * @param oldHead: A pointer to the previous head of the stack
 * @param data: an input double representing what data the element will hold
 */
struct element* push(struct element* oldHead, double data){
	struct element* temp = (struct element*)malloc(sizeof(struct element));
	temp->contents = data;
	temp->next = oldHead;
	if(oldHead==NULL) temp->stackSize=1;
	else temp->stackSize = ++(oldHead->stackSize);
	oldHead = temp;
	return oldHead;
}


/* Takes a pointer to a pointer the head element of the list.  
 * Gets the double value held in that element and creates a "temp" pointer to the location of the head 	* element
 * Then, changes the pointer to a pointer input to point to the next element in the stack,
 * effectively pointing to the second element as the new head
 * Then frees up the space held by the old head, pointed to by temp
 *
 * @param listHead: A pointer to a pointer to a stack element: ideally the head element
 */

double pop(struct element** listHead){
	printf("Starting pop: assigning value\n");
	double value = (*listHead)->contents;
	printf("%f\n",value);
	struct element *temp = *listHead;
	*listHead = (*listHead)->next;
	free(temp);
	return value;
}
