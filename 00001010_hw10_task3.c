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
#define NCOL 4
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
    printf("\n%X", *first);
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
    int i = 0, j = 0;
    FILE *infile = fopen(file1,"r");
    char str1[8], str2[8], str3[8];
    unsigned int header[3];
    if(infile == NULL)
    {
        printf("The file was not successfully opened\n");
        exit(1);
    }

    /* I updatedthe below code. The reason it wasn't fully working was
     * because you weren't resetting j to 0 after each inner while loop. It 
     * "appeared to partially work becuase the the fscanf is pulling as many
     * consective hex values before white space or a delimeter (comma in this
     * case). So each 'j' iteration grabs two hex values (e.g. FF). But since
     * j was only looping to 8, the j ran out and the loop was exited. Since
     * the fscanf pulls as many consecutive hex values as it sees, teh NCOL
     * is 4 instead of 8. I also
     * removed the i !=EOF and j `= '\n'. j and i are not being set to the 
     * fgetc or similar functions, and so they will never be the EOF or '\n'
     * characters.
     * Since we are already looping during the while loops I just put the 
     * "first" "second" and "third" arrays into the while loop using if 
     * statements. it just shortens the code slightly and uses less variables*/
    while(i < NROWS)
    {
        j = 0;
        while(j < NCOL)
        {
            switch (i)
            {
                case 0:
                    {
                        fscanf(infile, "%X", &first[j]);
                        break;
                    }
                case 1:
                    {
                        fscanf(infile, "%X", &second[j]);
                        break;
                    }
                case 2:
                    {
                        fscanf(infile, "%X", &third[j]);
                        break;
                    }
            }
            fgetc(infile);
            j++;
        }
        i++;
    }
    sprintf(str1, "%x%x%x%x", first[0], first[1], first[2], first[3]);
    sprintf(str2, "%x%x%x%x", second[0], second[1], second[2], second[3]);
    sprintf(str3, "%x%x%x%x", third[0], third[1], third[2], third[3]);
    header[0] = strtol(str1, NULL, 16);
    header[1] = strtol(str2, NULL, 16);
    header[2] = strtol(str3, NULL, 16);
    for (i = 0; i < 3; i++)
    {
        printf("%X\n", header[i]);
    }
}
