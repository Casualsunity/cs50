/**
 * This program should tell the user how many days are in the particular month of a particular year.
 * Fan Sun
 * 11.12.16
*/
#include <stdio.h>
#include <cs50.h>

int leap_year(int year);

int main (void) 
{
    
    int year;
    int month;
    int days;
    
    printf("Which year? \n");
    year = GetInt();
    if (leap_year(year) == 1)
        printf("this is a leap year.\n");
    else
        printf("this is a normal year.\n");
    
    printf("Which month? \n");
    month = GetInt();
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        printf("And there are %d days in this month\n", days);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        printf("And there are %d days in this month\n", days);
    case 2:
        if (leap_year(year) == 1)
        {
            days = 29;
            printf ("And there %d days in this month\n", days);
        }
        else
        {
            days = 28;
            printf("And there %d days in this month\n", days);
        }
        break;
    default:
        printf("Please enter a valid month. From 1 between 12. \n");
        break;
    }   
//list all leap year from 1700 to 2200
/*    for (year=2200; year >= 1700; year-- ){
        if (leap_year(year) == 1)
            printf("%d\t",year);
    }
    printf("\n");
*/
    return 0;
}

/* This function check the user input, if it is a leap year.*/
int leap_year(int year)
{
    bool leap_year;
    if (year%4 == 0)
        leap_year = true;
    else
        leap_year = false;
    return leap_year;
}
    