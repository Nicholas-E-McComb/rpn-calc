#include <math.h>
#include <stdio.h>

/*
 *	Takes two double inputs and one operator char and performs the requested operation
 *	on them.  
 *	@param d1: left-hand operand in the requested operation
 *	@param d2: right-hand operand in the requested operation
 *	@param op: Operator character: +,-,*,^, and / currently supported.  Checking for  
 *	invalid input happens in the main input loop.
*/
double operate(double d1, double d2, char op){
	int i;
	double total;
	if(op=='+'){
		printf("Adding %f and %f\n",d1,d2);
		return d1+d2;
	}
	else if(op=='-'){
		printf("Subtracting %f from %f\n",d1,d2);
		return d2-d1;
	}
	else if(op=='/'){
	 	if(d1==0){
			printf("Divide-by-zero error\n");
			return NAN;
		}
		else{
			printf("Dividing %f by %f\n",d1,d2);
			return d2/d1;
		}
	}
	else if(op=='*'){
		printf("Multiplying %f by %f\n",d1,d2);
		return d1*d2;
	}
	else if(op=='^'){
		if(d2==0) return 1.0;
		else{
			total = d1;
			for(i=1;i<d2;i++){
				total = total*d1;
			}
		return total;
		}
	}
	else{
		printf("Error: unrecognized operator %c\n",op);
		return NAN;
	}
}
