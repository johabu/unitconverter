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
	struct Inputs input;
	PrintLine();
	printf("\n unitconverter - version 0.2.2\n\n");
	PrintLine();
	input.quantity_switch = Menu(3,Quantities);
	switch (input.quantity_switch)
	{
		case 1: input = Inputf(input);
			input.output = input.input_number * Length_factors[input.YUnit][input.INUnit];
			break;
		case 2:	input = Inputf(input);
			input.output = input.input_number * Area_factors[input.YUnit][input.INUnit];
			break;
		default: Error(1);
	}
	Output(input.input_number, input.input_YUnit, input.output, input.input_INUnit);
	printf("\nThank you for using unitconverter!\n");
	return EXIT_SUCCESS;
}
