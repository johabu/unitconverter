/*
*	Unitconverter.c
*	Developed by Johabu <http://johabu.spheniscida.de>; <https://github.com/johabu/>
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
#include "unitconv_units.h"

int main(void) 
{
	struct Inputs input;
	PrintLine();
	printf("\n unitconverter - version 0.3.0\n\n");
	PrintLine();
	//user chooses the quantity
	input.quantity_switch = Menu(5,Quantities);
	switch (input.quantity_switch)
	{
		//if quantity=length
		case 1: input = Inputf(input);
			input.output = input.input_number * Length_factors[input.YUnit][input.INUnit];
			break;
		//if quantity=area
		case 2:	input = Inputf(input);
			input.output = input.input_number * Area_factors[input.YUnit][input.INUnit];
			break;
		//if quantity=volume
		case 3: input = Inputf(input);
			input.output = input.input_number * Volume_factors[input.YUnit][input.INUnit];
			break;
		//if quantity=time
		case 4: input = Inputf(input);
			input.output = input.input_number * Time_factors[input.YUnit][input.INUnit];
			break;
		//if quantity=temperature
		case 5: input = Inputf(input);
			input.output = TempConv(input);
			break;
		default: Error(1);
	}
	//output of the solution
	Output(input);
	printf("\nThank you for using unitconverter!\n");
	PrintLine();
	return EXIT_SUCCESS;
}
