/**
 * Einfach genial!
 * print a half-pyramid using hashes on the screen
 * input pyramid level less than 23
 * Programed by: Fan Sun
 * 11.12.16
 */

#include <stdio.h>
#include <cs50.h>

int hight_input();
void build(int level);
void build2(int level);
void build3(int level);


int main (void)
{
    int level;
    printf("How many levels do you want? (Maximal level is 23): ");
    level = hight_input();
    build(level);
    //build2(level);
    //build3(level);
}

/*check the inputs from user, if it is allowed.*/
int hight_input()
{
    int level;
    do 
    {
    level = GetInt();
    if (level < 0 )
        printf("Please enter a right number for the level! Thank you! \n");
    else if (level > 23)
        printf("Maximal level is 23, please choose a new number: \n");
    }
    while (level < 0||level > 23);
    return level;
}

void build(int level)
{
    for (int i = 1; i <= level; i++)
    {
        for (int j = (level-1); j >= i; j-- )
        {
            printf(" ");
        }
        for (int k =0 ; k<=i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

/*eine andere bauweise :D*/
void build2(int level)
{
    for (int i=1; i<=level; i++)
    {
        for (int j=level-1;j>=i;j--)
        {
            printf(" ");
        }
        for (int k=1; k<=i;k++)
        {
            printf("#");
        }
        
        for (int m = 1; m<=2; m++)
        {
            printf(" ");
        }
        for (int n= 1; n<=i; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}

/*vollpyramide*/
void build3(int level)
{
    for (int i=1; i<=level; i++)
    {
        for (int n=level; n>=i; n--)
        {
            printf(" ");
        }
        for (int j=1; j<=i;j++)
        {
            printf("#");
        }
        for (int k=2; k<=i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}