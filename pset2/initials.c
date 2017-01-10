/**
 * Benutzer gibt den Namen ein, und als output wird die Initialien ausgegeben.
 * Fan Sun
 *19.12.16
*/


#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h> //headerfile for toupper()


#define FL 0 //first letter is the first element of the string

int main(void)
{
    string name;
    do 
    {
        //printf("Please enter your name: ");
        name = GetString();
        int initials[strlen(name)];
        
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            if ((name[i] >= 'A' && name[i] <= 'Z')|| (name[i] >= 'a' && name[i] <= 'z')||name[i]==' ' )
            {
                //the first letter
                if (i == FL)
                {
                    //printf ("%d",i);
                    initials[i] = toupper(name[FL]);
                    printf("%c",initials[i]);
                }
                 //the letter after a space
                if (name[i]==' ')
                {
                    initials[i] = toupper(name[i+1]);//+1 means the letter after space
                    printf("%c",initials[i]);
                }
            } 
              
        }
    }while (name == NULL || name[0] == ' '); //
    printf("\n");
}