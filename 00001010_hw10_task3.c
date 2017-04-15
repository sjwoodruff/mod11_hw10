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

#define SIZE 81
/* global variables */
unsigned int nums[SIZE];
char in[SIZE];
/* Function Prototypes */
void Usage(char **info);
void ReadFile(char *file1, unsigned int num[]);
/* Main Program */
int main (int argc,     char *argv[])
{
    if(argc != 2 || (strcmp(*(argv+1),"--help") == 0))
    {
        Usage(argv);
    }
    strcpy(in,argv[1]);
    ReadFile(in,nums);
    
    return 0;
}


/* Function Defenitions */

void Usage(char **info)
{
    printf("\nUsage: .%s <mp3Header.txt>\n\n",*info); 
    return;
}

void ReadFile(char *file1, unsigned int num[])
{
    int i = 0;
    FILE *infile = fopen(file1,"r");
    if(infile == NULL)
    {
        exit(1);
    }
    
    while(fscanf(infile, "%X" , &num[i])!= EOF)     
    {
        fgetc(infile);
        printf("%X", num[i]);
        i++;
    }
      
    return;
}
