/*
 * =====================================================================================
 *
 *       Filename:  0001010_hw10_task2.c
 *       	Usage:  ./0001010_hw10_task2.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2017 11:26:39 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Sterling Woodruff (), sterlingwoodruff@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>    /* For String library */
/* Function Prototypes */
void Usage(char** info);

/* Main Program */
int main (int argc, char *argv[])
{
    // Call Usage funciton if there is not one string or if --help is the
    // first string
    if (argc != 2 || (strcmp(*(argv+1),"--help") == 0))
    {
        Usage(argv);
    }

	return 0;
}


/* Function Defenitions */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  Usage
 *  Description:  Explains how the funciton shoudl be used
 *    Arguments:  Array of inputs when program is run (argv)
 *      Returns:  Nothing
 * =====================================================================================
 */
void Usage (char** info)
{
    // Display how to use the program
    printf("Usage");
    printf("%s <dataFile>\n", *info);
    exit(1);
    return;
}		/* -----  end of function Usage  ----- */

