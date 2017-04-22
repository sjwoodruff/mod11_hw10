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
// I removed the global variables just because I think I remember Hugo saying
// that it is best practice not to set global variables unless they are 
// absolutely neccessary. This is because the program will take less memory
// to run if local variables are used (memory is freed up when the funciton
// is complete if  the variable is local to the funciton. I also took out the 
// "in" array that stored the argv[1] value...since you can just pass the 
// argv[1] value. That way it uses less memory I think. -- Chris

/* Function Prototypes */
void Usage(char **info);
void ReadFile(char *file1, unsigned int num[]);
void DispMPEG(unsigned int val);

/* Main Program */
int main (int argc,     char *argv[])
{
    // Declare variables
    unsigned int nums[NROWS];
    if(argc != 2 || (strcmp(*(argv+1),"--help") == 0))
    {
        Usage(argv);
    }
    ReadFile(argv[1],nums);
    // Save the previous array so information is not overwritten
    for (int i = 0; i < NROWS; i++)
    {
        // Call funciton to Display MPEG version
        DispMPEG(nums[i]);
        // Call function to Display Layer
        // Call function to display sampling Rate
    }
    return 0;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  Usage
 *  Description:  Help Function
 *    Arguments:  requires the right inputs or --help
 *      Returns:  Nothing
 * =====================================================================================
 */

void Usage(char **info)
{
    printf("\nUsage: .%s <mp3Header.txt>\n\n",*info); 
    exit (1);
    return;
}
/* -----  end of function Usage  ----- */



/*
 * ===  FUNCTION  ======================================================================
 *         Name:  ReadFile
 *  Description:  Reads the file and stores the data as unsigned int
 *    Arguments:  File to be read, unsigned int array
 *      Returns:  Nothing
 * =====================================================================================
 */
void ReadFile(char *file1, unsigned int num[])
{
    // Declare variables
    int i = 0, j = 0;
    unsigned int first[SIZE], second[SIZE], third[SIZE];
    FILE *infile = fopen(file1,"r");
    char str1[8], str2[8], str3[8];
    if(infile == NULL)
    {
        printf("The file was not successfully opened\n");
        exit(1);
    }
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
    num[0] = strtol(str1, NULL, 16);
    num[1] = strtol(str2, NULL, 16);
    num[2] = strtol(str3, NULL, 16);
    for (i = 0; i < 3; i++)
    {
        printf("%X\n", num[i]);
    }
}
/* -----  end of function Usage  ----- */


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  MPEG Version
 *  Description:  Perform bitwise function to determine mpeg version
 *    Arguments:  File to be read, unsigned int array
 *      Returns:  Nothing
 * =====================================================================================
 */





/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DispMPEG
 *  Description:  Determines and Displays the MPEG version
 *    Arguments:  Array containing header file
 *      Returns:  Nothing
 * =====================================================================================
 */
void DispMPEG (unsigned int val)
{
    // Declare variables
    float vers;
    printf("Hex value is %x\n", val);
    // Perform Bitwise operation to set all bits but 19 and 20 to zero 
    val = val & 0x180000;
    printf("Hex value is %x\n", val);
    // Perform Bitwise operation to make bits 19 and 20 be the first two bits
    val = val >> 19;
    printf("Hex value is %x\n", val);
    switch (val)
    {
        case 0:
        {
            vers = 2.5;
            break;
        }
        case 2:
        {
            vers = 2;
            break;
        }
        case 3:
        {
            vers = 1;
            break;
        }
    }
    printf("[%d] MPEG  Version %.1f\n", val, vers);
    return;
}		/* -----  end of function DispMPEG  ----- */
