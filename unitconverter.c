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
	int convert_again = 1;
	PrintLine();
	printf("\n unitconverter - version 0.3.2\n\n");
	PrintLine();
	while (convert_again == 1) {
		//user chooses the quantity
		printf("\nChoose quantity by entering the corresponding number.\n0:\tExit\n");
	        input.quantity_switch = Menu(7,Quantities);
	        switch (input.quantity_switch) {
	                //if quantity=length
        	        case 1: input = Inputf(input);
                	        input.output = input.input_number * Length_factors[input.YUnit][input.INUnit];
	                        break;
	                //if quantity=area
	                case 2: input = Inputf(input);
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
	                //if quantity=velocity
	                case 6: input = Inputf(input);
	 	                input.output = input.input_number * Velocity_factors[input.YUnit][input.INUnit];
	                        break;
			//if quantity=mass
                        case 7: input = Inputf(input);
                                input.output = input.input_number * Mass_factors[input.YUnit][input.INUnit];
                                break;
			case 0: convert_again = 0;
				break;
	                default: Error(1);
	        }
	        //output of the solution
	        if (convert_again != 0) {
			Output(input);
		}
		//printf("Convert again? Enter '1'\n");
		//scanf("%d",&convert_again);
	}
	printf("\nThank you for using unitconverter!\n");
	PrintLine();
	return EXIT_SUCCESS;
}
