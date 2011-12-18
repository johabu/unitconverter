/*
*	Unitconverter.c
*	Developed by Johabu <http://johabu.spheniscida.de>
*	
*	This file is part of unitconverter.
*	unitconverter is free software; you can modify it or redistribute it 
*	under the terms of the GNU General Public License as published by
*	the Free Software Foundation <http://www.fsf.org>, either version 3,
*	or (at your option) any later version.
*	See <http://www.gnu.org/licenses> for the license, if you
*	haven't received a copy of it (GNU_GPL.txt).
*
*	unitconverter is distributed without any warranty!
*/
#include <stdlib.h>
#include <stdio.h>
#include "unitconv_func.h"

int main(int argc, char *argv[]) 
{
	int quantity_switch, INUnit, YUnit;
	float input_number,output;
	char input_YUnit[3], input_INUnit[3];
	PrintLine();
	printf("\n unitconverter - version 0.1.9\n\n");
	PrintLine();
	quantity_switch = Menu(2,Quantities);
	switch (quantity_switch)
	{
		case 1: printf("Enter your unit:\n");
			scanf("%s",&input_YUnit[0]);
			YUnit = CheckUnit(quantity_switch,input_YUnit);
			printf("Enter your value [%s]:\n",input_YUnit);
			scanf("%f",&input_number);
			printf("Enter the unit in which you want to convert [%s]:\n",input_YUnit);	
			scanf("%s",&input_INUnit[0]);
			INUnit = CheckUnit(quantity_switch,input_INUnit);
			output = input_number*Length_factors[YUnit][INUnit];
			break;
		case 2:	Error(2);
			break;
		default: Error(1);
	}
	Output(input_number, input_YUnit, output, input_INUnit);
	return EXIT_SUCCESS;
}
