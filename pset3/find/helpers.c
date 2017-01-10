/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
//function declaration:
//bool search(int value, int values[], int n)
/**
 * Linie Search:
*/

    /*  
{    
        for (int i = 0; i < n; i++)
        {
            if (values[i] == value)
                return true;
        }
        return false;   
} 
    */

/**
 * binäre Suche
 * Divid Et Impera
 * 
 * Psodocode:
 * Voraussetzung: list ist sortiert.
 * 
 * Der list wird geteilt durch 2.
 * Ist gesuchte wert genau in der Mitte?
 * Ja -> Fertig. 
 * nein -> 
 *  Ist der gesuchte Wert kleiner als Mittelwert?
 *  Ja ->
 *      max ist mittelwert, i ist 0
 *      list erneut durch 2.
 *      
 *  nein ->
 *      max ist n, i ist mittlewert.
 *  
 *
 *
*/

        
bool search(int value, int values[], int n) //ACHTUNG! bool!
{
    int left =0;
    int right = n;
    int middle;
    while(right >= left) 
    {
      middle = (left + right) / 2;
      if(value < values[middle]) /* kleiner? */
         right = middle-1;  /* Rechte Seite ist nicht mehr so interessant. */
       else      /* dann halt größer */
         left = middle+1;  /* Linke Seite ist nicht mehr so interessant. */
       if(value == values[middle])
          return true;     /* gefunden; x = Position */
    }
     return false; /* nicht gefunden */
}
    
    
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
/**
 * Selection Sort:
 * for i = 1 to n - 1
 *  min = i
 *  for j = i + 1 to n
 *      if array[j] < array[min]
 *          min = j
 *      if min != i
 *      swap array[min] and array[i]
 */
    int min;
    int i;
    for (i= 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[min]) 
            {
                min = j; // der Schlüssel ist nur mit dem Index zu spielen.
            }
        }
         //  printf("min = %d ",values[min]);
         //  printf("i = %d \n",values[i]);
        if (min != i)
        {
           int tmp      = values[min];
           values[min]  = values[i];
           values[i]    = tmp;
        }
    }
    // for (int i = 0; i< n; i++)
    // {
    //    printf("%d|",values[i]);
    // }
}