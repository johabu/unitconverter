#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unitconv_units.h"

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
