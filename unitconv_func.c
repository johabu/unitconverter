#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unitconv_units.h"
#include "unitconv_func.h"
/*struct Inputs {
		int quantity_switch;
		int YUnit;
		int INUnit;
		double input_number;
		double output;
		char input_YUnit[4];
		char input_INUnit[4];
	}; 

char *Error_types[] = {"Error - Unknown quantity!","Error - Not available!","Error - Unknown unit!","Please restart the program!"};
*/
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
	for (i=0; i <= (Quantity_units_num[Units-1] - 1); i++) {
		if (strcmp(input,Units_short[Units-1][i]) == 0) 
		{
			return i;
			break;
		}
	}
	if (strcmp(input,"help") == 0) 
	{
		printf("\nAvailable units:\n");
		for (i=0; i <= 11; i++) {
			printf("%s\n",Units_long[Units-1][i]);
		}
		return 255;
	} 
	else
	{
		printf("%s\n",Error_types[2]);
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
	while (structure.YUnit == 255) {
		printf("Enter your unit: ('help' for a list of available units)\n");
		scanf("%s",&structure.input_YUnit[0]);
		structure.YUnit = CheckUnit(structure.quantity_switch, structure.input_YUnit);
	}
	printf("Enter your value [%s]:\n",structure.input_YUnit);
	scanf("%lf",&structure.input_number);
	structure.INUnit = 255;
	while (structure.INUnit == 255) {
		printf("Enter the unit in which you want to convert [%s]: ('help' for a list of available units)\n",structure.input_YUnit);	
		scanf("%s",&structure.input_INUnit[0]);
		structure.INUnit = CheckUnit(structure.quantity_switch, structure.input_INUnit);
	}
	return structure;
}
