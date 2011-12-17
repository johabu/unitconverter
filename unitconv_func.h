#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unitconv_units.h"

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
		return 254;
	} else
	{
		return 255;
	}
}
