#include "TicTacToe.h"


void print_grid(char arr[])
{
    int k = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            // if the index of j is even (Cell no. 2), print the two pipes constructing the grid
            if (j % 2 == 0)
            {
                //%3c this 3 is intended to give each character the same space to achieve alignment 
                printf("|%5c |", arr[k]);   
                k++;
            }
            else
            {
                //we use k to iterate over the single array
                printf("%5c ", arr[k]);
                k++;

                // when j = 3||6||9 break from the inner loop and increment the outer loop 
                // to create that 3x3 grid look
                if (j % 3 == 0)
                    break;
            }
        }
        printf("\n ----------------\n");
    }
}
void show_instructions()
{
    char arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
     int k = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (j % 2 == 0)
            {
                printf("| %d | ", arr[k]);   
                k++;
            }
            else
            {
                printf(" %d ", arr[k]);
                k++;
                if (j % 3 == 0)
                    break;
            }
        }
        printf("\n ------------\n");
    }

}
int used_pos[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int unique_pos(int pos)
{
    // we started all operations on the grid from 1 not 0
    if (pos == 0)
    {
        printf("\nThere is no such position, please choose another \n");
        scanf("%d", &pos);
    }
    else
    {
        // the concept behind used_pos[] is the same as hash table
        // used_pos[3] = 3, the pos == the value
        while (used_pos[pos] == 0)
        {
            printf("\nPosition already taken, Please choose another\n");
            scanf("%d", &pos);
        }
        used_pos[pos] = 0;
    }

    return pos;
}

//changed the type to char * 
// should also change static char grid[9] = {};
char *populate_grid(int pos, char c)  
{
    grid[pos] = c;
    print_grid(grid);
    return grid;
}

int check_rows(char *gptr, char val)
{
    int flag = 0;
    if (((gptr[1] == val) && (gptr[2] == val) && (gptr[3] == val)) ||
        ((gptr[4] == val) && (gptr[5] == val) && (gptr[6] == val)) ||
        ((gptr[7] == val) && (gptr[8] == val) && (gptr[9] == val)))
    {

        flag = 1;
    }
    return flag;
}

int check_cols(char *gptr, char val)
{
    int flag = 0;
    if (((gptr[1] == val) && (gptr[4] == val) && (gptr[7] == val)) ||
        ((gptr[2] == val) && (gptr[5] == val) && (gptr[8] == val)) ||
        ((gptr[3] == val) && (gptr[6] == val) && (gptr[9] == val)))
    {
        flag = 1;
    }
    return flag;
}

int check_diagonal(char *gptr, char val)
{
    int flag = 0;
    if (((gptr[1] == val) && (gptr[5] == val) && (gptr[9] == val)) ||
        ((gptr[3] == val) && (gptr[5] == val) && (gptr[7] == val)))
    {

        flag = 1;
    }
    return flag;
}

int winning_algorithm(char *gptr)
{
    int flag = 0;
    // check X
    if (check_rows(gptr, first_player_char) || check_cols(gptr, first_player_char) || check_diagonal(gptr, first_player_char))
    {
        printf("\n------------ Winner is X ------------\n");
        flag = 1;
    }

    // check O
    else if (check_rows(gptr, second_player_char) || check_cols(gptr, second_player_char) || check_diagonal(gptr, second_player_char))
    {
        printf("\n------------ Winner is O ------------\n");
        flag = 2;
    }

    else
    {
        flag = 3;
    }

    return flag;
}

void execute()
{
    int x_pos = 0, o_pos = 0, t = 9;
    char *updated_grid = NULL;  
    while (t--)
    {
//Used this odd and even to ulternate between input X and O
        if (!(t % 2 == 0))
        { // if t is odd
            printf("Choose a position (X) : ");
            scanf("%d", &x_pos);
            int px = unique_pos(x_pos);
            updated_grid = populate_grid(px, first_player_char);
        }
        else
        {
            printf("Choose a position (O) : ");
            scanf("%d", &o_pos);
            int po = unique_pos(o_pos);
            updated_grid = populate_grid(po, second_player_char);
        }

// Once the third position of X or O has been chosen
//Only then we can start checking for winner.
        if (t < 5)
        {
            int f = winning_algorithm(updated_grid);
            if (f != 0 && f != 3)
            {
                break;
            }
            else if (!t)
            {
                printf("\n------------ Draw ------------\n");
            }
        }
    }
}