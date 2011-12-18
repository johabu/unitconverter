#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unitconv_units.h"

struct Inputs {
		int quantity_switch;
		int YUnit;
		int INUnit;
		float input_number;
		float output;
		char input_YUnit[3];
		char input_INUnit[3];
	}; 

char *Error_types[] = {"Unknown quantity!","Not available!","Unknown unit!"};

void PrintLine() {
	printf("===============================\n");
}

int Menu(int options_num, char *options_name[options_num]) 
{
	int i,selection;
	printf("\n");
	for (i = 1; i <= options_num; i++) 
	{
		printf("%d:\t%s\n",i,options_name[i-1]);
	}
	scanf("%d",&selection);
	printf("You selected: %s\n",options_name[selection-1]);
	return selection;
}

int CheckUnit(int Units, char input[3]) {
	int i;
	for (i=0; i <= 11; i++) {
		if (strcmp(input,Units_short[Units-1][i]) == 0) 
		{
			return i;
			break;
		}
	}
	if (strcmp(input,"help") == 0) 
	{
	} 
	else
	{
		Error(3);
	}
}

int Error(int error_type) {
		printf("\nERROR - %s\n",Error_types[error_type-1]);
		exit(EXIT_FAILURE);
}

void Output(float input, char yunit[3], float output, char inunit[3]) {
	PrintLine();
	printf(" %s --> %s\n",yunit,inunit);
	printf(" Solution:\n\t%g %s = %g %s\n",input,yunit,output,inunit);
	PrintLine();
}

struct Inputs Inputf(struct Inputs structure) {
	printf("Enter your unit:\n");
	scanf("%s",&structure.input_YUnit[0]);
	structure.YUnit = CheckUnit(structure.quantity_switch, structure.input_YUnit);
	printf("Enter your value [%s]:\n",structure.input_YUnit);
	scanf("%f",&structure.input_number);
	printf("Enter the unit in which you want to convert [%s]:\n",structure.input_YUnit);	
	scanf("%s",&structure.input_INUnit[0]);
	structure.INUnit = CheckUnit(structure.quantity_switch, structure.input_INUnit);
	return structure;
}
