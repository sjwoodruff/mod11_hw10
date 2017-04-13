/*
 * =====================================================================================
 *
 *       Filename:  00001010_hw10_task1.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/13/2017 03:52:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sterling Woodruff (), sterlingwoodruff@mail.weber.edu
 *   Organization:  
 *
 * =====================================================================================
 */
// Define structure
struct house
{
    int num;
    char name[25];
    float price;
};

/* Funciton Prototypes */
struct house InputHouse(void);
void PrintHouse(char *name, struct house h);

