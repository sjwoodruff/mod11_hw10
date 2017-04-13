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

#define NUMRECS 10 

struct Tsunami
{
    int mo, da, yr, fatalities;
    double max_height;
    char location[20];
};

/* Function Prototypes */
void Usage(char** info);
void ReadFile(char** data, struct Tsunami waves[]);
void DisplayReport(struct Tsunami waves[]);

/* Main Program */
int main (int argc, char *argv[])
{
    // Declare variables
    struct Tsunami waves[NUMRECS];
    // Call Usage funciton if there is not one string or if --help is the
    // first string
    if (argc != 2 || (strcmp(*(argv+1),"--help") == 0))
    {
        Usage(argv);
    }

    ReadFile(argv, waves);
    DisplayReport(waves);
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
}
/* -----  end of function Usage  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  ReadFile
 *  Description:  Reads the data file and stores the data in Tsunami struct
 *    Arguments:  Takes the input file name (data) and an array of Tsunami structures
 *      Returns:  Nothin
 * =====================================================================================
 */
void ReadFile (char** data, struct Tsunami waves[])
{
    // Declare and initialize inFile
    FILE *inFile = fopen(*(data+1),"r");
    if (inFile == NULL)
    {
        printf("Failed to open the file");
        exit(1);
    }
    for (int i = 0; i < NUMRECS; i++)
    {
        fscanf(inFile,"%d", &waves[i].mo);
        fscanf(inFile,"%d", &waves[i].da);
        fscanf(inFile,"%d", &waves[i].yr);
        fscanf(inFile,"%d", &waves[i].fatalities);
        fscanf(inFile,"%lf", &waves[i].max_height);
        fscanf(inFile,"%s", waves[i].location);
    }
    fclose(inFile);

    return;
}		/* -----  end of function ReadFile  ----- */


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  DisplayReport
 *  Description:  Displays the report information gleaned from the input file
 *    Arguments:  The array "waves"
 *      Returns:  Nothing. Displays report on screen
 * =====================================================================================
 */
void DisplayReport (struct Tsunami waves[])
{
    // Declare variables
    double waveMax = 0, waveSum = 0, waveAve;
    // Loop through the data assigning highest value to waveMax 
    // and while getting the sum of the wave heights
    for (int i = 0; i < NUMRECS; i++)
    {
        waveSum += waves[i].max_height;
        if (waves[i].max_height > waveMax)
        {
            waveMax = waves[i].max_height;
        }
    }
    waveAve = waveSum/NUMRECS;
    // print report title
    printf("Summary Information for Tsunamis\n");
    printf("--------------------------------\n");
    // print max height
    printf("Maximum wave height in feet: %.2lf\n", waveMax*3.28);
    // print the average height
    printf("Average wave height in feet: %.2lf\n", waveAve*3.28);
    // Find and print the tsunamis wiht greater than average heights
    printf("Tsunamis wiht greater than average heights:\n");
    for (int i = 0; i < NUMRECS; i++)
    {
        if (waves[i].max_height > waveAve)
        {
            printf("%s\n", waves[i].location);
        }
    }
    return;
}		/* -----  end of function DisplayReport  ----- */
