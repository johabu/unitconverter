#ifndef UNITCONVFUNC
#define UNITCONVFUNC

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Inputs {
		int quantity_switch;
		int YUnit;
		int INUnit;
		double input_number;
		double output;
		char input_YUnit[5];
		char input_INUnit[5];
}; 


extern char *Error_types[]; 

extern void PrintLine(); 

extern int Quantity_units_num[];

extern int Menu(int options_num, char *options_name[options_num]);

extern int CheckUnit(int Units, char input[5]);

extern int Error(int error_type);

extern void Output(struct Inputs); 

extern struct Inputs Inputf(struct Inputs structure);

extern double TempConv(struct Inputs tempstruct);

#endif
