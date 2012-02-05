#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unitconv_units.h"
#include "unitconv_func.h"

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
		return 255;
	} 
	else {
		Error(3);
		return 255;
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
	printf(" %s --> %s\n",input.input_YUnit, input.input_INUnit);
	printf(" Solution:\n\t%g %s = %g %s\n",input.input_number, input.input_YUnit, input.output,input.input_INUnit);
	PrintLine();
}

struct Inputs Inputf(struct Inputs structure) {
	structure.YUnit = 255;
	int prv;
	while (structure.YUnit == 255) {
		printf("Enter your unit: ('help' for a list of available units)\n");
		prv = scanf("%s",&structure.input_YUnit[0]);
		if (prv != 1) 
                        Error(4);
		structure.YUnit = CheckUnit(structure.quantity_switch, structure.input_YUnit);
	}
	printf("Enter your value:\n");
	prv = scanf("%lf",&structure.input_number);
	if (prv != 1) 
                Error(4);
	structure.INUnit = 255;
	while (structure.INUnit == 255) {
		printf("Enter the unit in which you want to convert: ('help' for a list of available units)\n");	
		prv = scanf("%s",&structure.input_INUnit[0]);
		if (prv != 1)
                        Error(4);
		structure.INUnit = CheckUnit(structure.quantity_switch, structure.input_INUnit);
	}
	return structure;
}
