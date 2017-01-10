/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
//void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    //greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("geschafft!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 * 
 * Also durch init Funktion wird das Spielbrett definiert, jede Zahl
 * ist eindeutig, damit die draw funktion korrekte ausgabe geben kann.
 */
 

void init(void)
{
    int grid_value = d*d - 1;
    //OMG!!! ich redeklarierte diese globale Variable nochmals lokal, kein Wunder dass draw() alle 0 gemalt hat!
    //int board[d][d];
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if(d % 2 == 0)
            {
                if (i == (d -1) && j == (d - 3))
                {
                    board[i][j] = grid_value - 1;
                }
                else if (i == (d - 1) && j == (d -2))
                {
                    board[i][j] = grid_value + 1;
                }
                else
                {
                    board[i][j] = grid_value;
                }
            }
            else if (d % 2 != 0)
            {
                board[i][j] = grid_value;
            }
            grid_value--;    
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    printf("\n");
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" %2c", 95);
            }
            else
            {
                printf(" %2d", board[i][j]);            
            }
        }
        printf("\n");
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile) // Wichtig, parameter tile zu Erst betrachten...!
// Konnte nicht weiter kommen, da ich nicht geachtet habe, dass das Input tile existiert.
// tmp = a; a = b; b = tmp
{
    // legale Bewegungen: wenn board[i][j] = 6(die 0 als "_"ist bei 6) => 
    // board[i-1][j] board[i+1][j] board[i][j-1] board[i][j+1]
    // aus diesem Prinzip sucht man wo 0(_) ist
    int tmp[1][1]; // eine 1x1 array, also eine zelle für den Tausch.
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0 && board[i][j-1] == tile)
            {
                tmp[0][0] = board[i][j];
                board[i][j] = board[i][j - 1];
                board[i][j - 1] = tmp[0][0];
                return true;
            }
            else if (board[i][j] == 0 && board[i][j + 1] == tile)
            {
                tmp[0][0] = board[i][j];
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = tmp[0][0];
                return true;
            }
            else if (board[i][j] == 0 && board[i - 1][j] == tile)
            {
                tmp[0][0] = board[i][j];
                board[i][j] = board[i - 1][j];
                board[i - 1][j] = tmp[0][0];
                return true;
            }
            else if (board[i][j] == 0 && board[i + 1][j] == tile)
            {
                tmp[0][0] = board[i][j];
                board[i][j] = board[i + 1][j];
                board[i + 1][j] = tmp[0][0];
                return true;
            }

        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int right_value[d][d];
    int value = 1; //alle erste zahl ist gleich 1.
    int counter = 1; // zählt die richtige positionen.
    // eine richtige reihenfolge also die läsung darstellen.
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            right_value[i][j] = value;
            value++;
        }
    }
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j]==right_value[i][j])
                counter++;
        }
    }
    if (counter == d*d)
        return true;
    else
        return false;
}

