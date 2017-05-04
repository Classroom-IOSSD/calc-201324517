#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result = 0;
	int line = 0;
	double (*operator_pointer)(int,int);

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				//result = add(operand1, operand2);
				operator_pointer = add;
				break;
				case '-':
				//result = minus(operand1, operand2);
				operator_pointer = minus;
				break;
				case '*':
				//result = mul(operand1, operand2);
				operator_pointer = mul;
				break;
				case '/':
				//result = div(operand1, operand2);
				operator_pointer = div;
				break;
			}
			result = operator_pointer(operand1, operand2);
		
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

