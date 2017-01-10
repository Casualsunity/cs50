/**
 * Vigenere's Cipher
 * input a keyword with command line argument
 * if the input is not a word or NULL or more than 1 word, program exit with 1 and complain
 * enter the plaintext p
 * encrypt the plaintext and exit with 0
 * 
 * Anmerkungen: A bzw a sollte 0 also alle Buchstaben fängt bei 0 an zu zählen...
 * other symbols, numbers must be leaved unchanged, 
 * Fan Sun
 * 21.12.16
 */
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h> //for the atoi function
#include <ctype.h> //isdigit,islower,isprint and much more check the manual
#include <string.h>

//eliminate the difference between letter position in real time and ASCII Value
#define CaptL  65
#define SmallL 97

void viCipher(string keyword);

int main (int argc, char* argv[])
{
    string keyword;
    if (argc >= 2) //the 2nd input 
    {
        if (argc > 2)
        {
            printf("To much inputs, only the 2nd element will be considered!");
            return 1;
        }
        else //argc==2 and input are valid
        {
            keyword = argv[1]; //the 2nd element of string array.
            
            for (int i=0, n=strlen(keyword); i<n; i++)
            {
                if (!isalpha(keyword[i]))
                {
                    printf("Please only Alphabet as a keyword\n");
                    return 1;
                }
            }
            viCipher(keyword);
        }
    }
    else 
    {
        printf("Please enter a keyword!\n");
        return 1;
    }
    return 0;
}

void viCipher(string keyword)
{
    string plainT = GetString();
    string cipherT = plainT;
    //the length of the text and keyword n%m 
    //the modulo of the keyword will make keyword to circle around
    int n = strlen(plainT);
    int m = strlen(keyword); //length to wrap around just like 26 by caeser.c
    int shift[m];
    
    //shift position with letters
    for (int i = 0; i < m; i++)
    {
        if(isupper(keyword[i]))
            shift[i] = keyword[i] - CaptL;
        else if (islower(keyword[i]))
            shift[i] = keyword[i] - SmallL;
    }
    
    
    //!!!j wird erst erhöht wenn eingabe ein Buchstabe ist und nicht leertaste ist.Zeile 85/89
    //i%m bedeutet einfach dass nach m element wiederholen
    //z.B wenn Text 6 Element(ABCDEF) hat, und Key nur 3 Elemente (ABC). Der Key sollte ABC, ABC sein. 
    for (int i = 0, j=0; i < n; i++)//
    {
        if (isupper(plainT[i]))
        {    
            cipherT[i] = (plainT[i] - CaptL + (shift[j++ % m])) % 26 + CaptL;  
        }
        else if (islower(plainT[i]))
        {
            cipherT[i] = (plainT[i] - SmallL + (shift[j++ % m])) % 26 + SmallL;
        }
        else if (isspace(plainT[i]))
        {
            cipherT[i] = plainT[i];
        }
        printf("%c",cipherT[i]);
    }
    printf("\n");
}


