/**
Test array
*/

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    /*
    int n = 2;
    int array[10] = {9,8,7,6,5,4,3,2,1,0};
    
    printf("array[n]: %d\n", array[n]);
    */
    
    
    int limits = 3;
    int feld[limits][limits];
    int grid = 1;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            feld[i][j] = grid;
            printf("feld %d",grid);
            grid++;

        }
    }
   
}