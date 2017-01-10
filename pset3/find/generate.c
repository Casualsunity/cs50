/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // without input in the command line, will quit the program with error return value.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // the string argv[1] becomes an integer value
    int n = atoi(argv[1]);

    // check the 3rd input from the command line.
    // if there is a 3rd input, call the function srand48(3rd input)
    // if not, the srand48(NULL) runs
    // srand48() initialised / seeds the pseudorandom generator drand48()
    
    // Startwert genannt – ist ein Wert, mit dem ein Zufallszahlengenerator 
    // initialisiert wird. Der Zufallszahlengenerator erzeugt mit der Seed 
    // als Startwert eine Folge von Zufallszahlen bzw. Pseudozufallszahlen. 
    // Verwendet man in deterministischen Zufallszahlengeneratoren den gleichen Seed, 
    // so erhält man die gleiche Folge von Pseudozufallszahlen.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // The function drand48() returns 
    // a pseudorandom non-negative double-precision floating-point value 
    // over the interval [0.0, 1.0).
    
    // based on the value n, n times pseudorandom number will be generaded
    // *LIMIT = 65536 is a factor to make the number bigger, because normaly
    // drand48() generatet double number between 0.0 to 1.0
    // and cast the double value to a big integer number 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
      //  printf("%f\n", drand48());
    }

    // success
    return 0;
}