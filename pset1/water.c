#include <stdio.h>
#include <cs50.h>



int main(void)
{
    int min = 0;
    double water_amount_gallon = 1.5;
    double water_amount_ounces = 128 * water_amount_gallon;
    double bottle_water = water_amount_ounces/16;
    double water_spend;
    
    printf("How much time (in minutes) do you spend for shower? \n");
    min = GetInt();
    water_spend = bottle_water * min;
    printf("%d minutes shower uses %.0f bottles of water!\n",min,water_spend);
}