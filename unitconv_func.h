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
		char input_YUnit[4];
		char input_INUnit[4];
	}; 


extern char *Error_types[]; 

extern void PrintLine(); 

extern int Menu(int options_num, char *options_name[options_num]);

extern int CheckUnit(int Units, char input[3]);

extern int Error(int error_type) ;

extern void Output(struct Inputs); 

extern struct Inputs Inputf(struct Inputs structure) ;

#endif
