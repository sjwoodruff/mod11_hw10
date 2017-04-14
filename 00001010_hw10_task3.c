/*
 * =====================================================================================
 *
 *       Filename:  0001010_hw10_task3.c
 *       	Usage:  ./0001010_hw10_task3.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2017 11:26:53 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Sterling Woodruff (), sterlingwoodruff@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>
/* Function Prototypes */
void Usage(char **info);

/* Main Program */
int main (int argc, char *argv[])
{
    
    if(argc != 2 || (strcmp(*(argv+1),"--help") == 0))
    {
        Usage(argv);
    }

	return 0;
}


/* Function Defenitions */

void Usage(char **info)
{
    printf("\nUsage: .%s <mp3Header.txt>\n\n",*info); 
    return;
}

