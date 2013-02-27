#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unitconv_units.h"
#include "unitconv_func.h"

#define ND 255
//ND: Not Defind

void PrintLine() {
	printf("===============================\n");
}

int Menu(int options_num, char *options_name[options_num]) {
	int i,selection;
	int prv;
	printf("\n");
	for (i = 1; i <= options_num; i++) {
		printf("%d:\t%s\n",i,options_name[i-1]);
	}
	prv = scanf("%d",&selection);
	if (prv != 1) 
                Error(4);
	return selection;
}

int CheckUnit(int Units, char input[5]) {
	int i;
	for (i=0; i <= (Quantity_units_num[Units-1] - 1); i++) {
		if (strcmp(input,Units_short[Units-1][i]) == 0) {
			return i;
			break;
		}
	}
	if (strcmp(input,"help") == 0) {
		printf("\nAvailable units:\n");
		for (i=0; i <= (Quantity_units_num[Units-1] - 1); i++) {
			printf("%s\n",Units_long[Units-1][i]);
		}
		return ND;
	} 
	else {
		Error(3);
		return ND;
	}
	return 0;
}

int Error(int error_type) {
		printf("\n%s\n",Error_types[error_type-1]);
		PrintLine();
		exit(EXIT_FAILURE);
}

void Output(struct Inputs input) { 	
	PrintLine();
	printf(" Solution:\n\t%g %s = %g %s\n",input.input_number, input.input_YUnit, input.output,input.input_INUnit);
	PrintLine();
}

struct Inputs Inputf(struct Inputs structure) {
	structure.YUnit = ND; 
	int prv;
	while (structure.YUnit == ND) {
		printf("\nEnter your unit: ('help' for a list of available units)\n");
		prv = scanf("%s",&structure.input_YUnit[0]);
		if (prv != 1) 
                        Error(4);
		structure.YUnit = CheckUnit(structure.quantity_switch, structure.input_YUnit);
	}
	printf("Enter your value:\n");
	prv = scanf("%lf",&structure.input_number);
	if (prv != 1) 
                Error(4);
	structure.INUnit = ND;
	while (structure.INUnit == ND) {
		printf("Enter the unit in which you want to convert: ('help' for a list of available units)\n");	
		prv = scanf("%s",&structure.input_INUnit[0]);
		if (prv != 1)
                        Error(4);
		structure.INUnit = CheckUnit(structure.quantity_switch, structure.input_INUnit);
	}
	return structure;
}

double TempConv(struct Inputs tempstruct) {
	if (tempstruct.YUnit == tempstruct.INUnit) {
		tempstruct.output = tempstruct.input_number;
	}
	if (tempstruct.YUnit == 0 && tempstruct.INUnit == 1) {
		tempstruct.output = (tempstruct.input_number*1.8 + 32);
	}
	if (tempstruct.YUnit == 0 && tempstruct.INUnit == 2) {
		tempstruct.output = tempstruct.input_number+273.15;
	}
	if (tempstruct.YUnit == 1 && tempstruct.INUnit == 0) {
		tempstruct.output = (tempstruct.input_number-32)*0.5555555556;
	}
	if (tempstruct.YUnit == 1 && tempstruct.INUnit == 2) {
		tempstruct.output = (tempstruct.input_number+459.67)*0.5555555556;
	}
	if (tempstruct.YUnit == 2 && tempstruct.INUnit == 0) {
		tempstruct.output = tempstruct.input_number-273.15;
	}
	if (tempstruct.YUnit == 2 && tempstruct.INUnit == 1) {
		tempstruct.output = (tempstruct.input_number*1.8 - 459.67);
	}
	return tempstruct.output;
}
