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

#define NROWS 3
#define NCOL 8
#define SIZE 81
/* global variables */
unsigned int nums[SIZE];
unsigned int first[SIZE];
unsigned int second[SIZE];
unsigned int third[SIZE];

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
    printf("%X", first[1]);
    return 0;
}

/* Function Defenitions */

void Usage(char **info)
{
    printf("\nUsage: .%s <mp3Header.txt>\n\n",*info); 
    exit (1);
    return;
}

void ReadFile(char *file1, unsigned int num[])
{
    int hex[SIZE][SIZE];
    int i, j = 0;
    FILE *infile = fopen(file1,"r");
    if(infile == NULL)
    {
        printf("The file was not successfully opened\n");
        exit(1);
    }

    while(i < NROWS && i != EOF)   
    {
        while(j < NCOL && j != '\n')
        {
            fscanf(infile, "%X", &hex[i][j]);
            fgetc(infile);
            j++;
        }
        i++;
    }

    for(int s = 0; s < NCOL; s++)
    {
        first[s] = hex[0][s];
    }

    for(int s = 0; s < NCOL; s++)
    {
        second[s] = hex[1][s];
    }

    for(int s = 0; s < NCOL; s++)
    {
        third[s] = hex[2][s];
    }
    return;
}
