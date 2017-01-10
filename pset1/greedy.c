/**There are only 25, 10, 5 and 1 cent available to give back.
 * programed by: Fan Sun
 * date: 12.11.16
 * 
 */
 
#include <stdio.h>
#include <cs50.h>


int main (void)
{
    float input;
    input = GetFloat();

    int rest = input * 100;
    int coin = 0;
    
    while (rest > 0)
    {
        if (rest >=25)
        {
            rest = rest - 25;
            coin++;
            //printf("input : %d ",rest);
            //printf("25 Cent %d: \n",coin);
        }
        else if (rest >= 10)
        {
            rest = rest - 10;
            coin ++;
            //printf("input : %d ", rest);
            //printf("10 Cent %d: \n", coin);
        }
        else if (rest >= 5)
        {
            rest = rest - 5;
            coin ++;
            //printf("input : %d ", rest);
            //printf("5 Cent %d: \n", coin);
        }
        else if (rest >= 1)
        {
            rest = rest - 1;
            coin ++;
            //printf("input : %d ", rest);
            //printf("1 Cent %d: \n", coin);
        }
        else 
        printf("invalid input...\n");
    }
    printf("%d \n",coin);
}