#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"
#include "rpn.h"

#define MAX_INPUT_LEN 100

void getInput(){
	char buffer[MAX_INPUT_LEN];
	char strInput[MAX_INPUT_LEN];	
	double val1,val2,total;
	int counter=0;
	struct element *head = NULL;

	printf("Enter an equation (in RPN)\n");
	if(fgets(strInput, MAX_INPUT_LEN, stdin) != NULL){
		strcpy(buffer,strInput);
		char *p = strtok(buffer, " \t\n");		

		while(p != NULL){
			printf("%s\n", p);
			if(isdigit(p[0])){
				printf("Going to push it\n");
				head = push(head,atof(p));
			} 
			else if(p[0]=='0'){
				printf("It's a zero\n");
				head = push(head,0.0);
			}
			else if(ispunct(p[0])){
				printf("%s is punctuation\n",p);
				//In the first run of the algorithm, you need to pop two elements
				//printf("First run\n");
				val1=pop(&head);
				printf("First element popped\n");
				val2=pop(&head);
				printf("Second element popped\n");
				printf("Operating on %f and %f\n",val1,val2);
				val1=operate(val1,val2,p[0]);
				printf("Current total is %f\n",val1);
				head = push(head,val1);
				
				/*
				if(counter==0){
					printf("First run\n");
					val1=pop(&head);
					printf("First element popped\n");
					val2=pop(&head);
					printf("Second element popped\n");
					printf("Operating on %f and %f\n",val1,val2);
					total=operate(val1,val2,p[0]);
					printf("Current total is %f\n",total);
					counter++;
				}
				//All other runs you only need to pop once
				else{
					val1=pop(&head);
					total=operate(val1,total,p[0]);
				}
				*/
			}
			else{
				printf("Invalid input\n");
			}
				
			p = strtok(NULL, " \t\n");
		}
		printf("Your total: %f\n",val1);
		printf("Would you like to enter another equation?\n");
	}
}

int main(){
	getInput();

	return 0;
}
