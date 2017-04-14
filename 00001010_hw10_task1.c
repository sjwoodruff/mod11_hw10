/*
 * =====================================================================================
 *
 *       Filename:  housePrice.c
 *       	Usage:  ./housePrice.c
 *    Description:  Ask user to specify the address and price
 *    				of two house that are on sale
 *    				It prints out which of the two houses is cheaper
 *
 *        Version:  1.0
 *        Created:  03/06/2014 04:03:12 PM
 *       Compiler:  gcc
 *         Author:  Dr. Hugo Valle (), hugovalle1@weber.edu
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "00001010_hw10_task1.h" // Rename this to your name name_hw#_task#.h
/* Function Prototypes */

/* Main Program */
int main(int argc, char* argv[])
{
	printf("Enter info for first house\n");
	struct house firstHouse = InputHouse();
	printf("\nEnter info for second house\n");
	struct house secondHouse = InputHouse();

	PrintHouse("first house:", firstHouse);  
	printf("\n\n");
	PrintHouse("second house", secondHouse);
	printf("\n\n");

	int comparison = ComparePrices(firstHouse, secondHouse);
	switch(comparison)
	{
		case -1:
			printf("the first house is cheaper\n");
			break;

		case 0:
			printf("the two houses are equally expensive\n");
			break;

		case 1:
			printf("the second house is cheaper\n");
			break;

		default:
			printf("invalid comparison value %d, there must be a bug\n", comparison);
			break;
	}

	return 0;
}


/* Function Defenitions */
// 1) Function for InputHouse
struct house InputHouse(void)
{
    struct house hvalues;
    printf("Please enter the street Number:");
    scanf("%d", &hvalues.num);
    printf("Please enter the street Name:");
    scanf("%s",hvalues.name); 
    printf("Please enter the Price:");
    scanf("%f", &hvalues.price);
    printf("\n");
	return hvalues;
}
// 2) Function to PrintHouse info
void PrintHouse(char *name, struct house h)
{

   printf("%s at %d %s for [%.2f]", name, h.num, h.name, h.price); 
    return;
}

// 3) Function to Compare Prices
int ComparePrices(struct house first, struct house second)
{
    int i;
    if(first.price < second.price)
            {
                i = -1;
            }
    if(first.price == second.price)
            {
                i = 0;
            }
    if(first.price > second.price)
            {
                i = 1;
            }


    return i; 
}


