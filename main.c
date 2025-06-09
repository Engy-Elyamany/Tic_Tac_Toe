#include "TicTacToe.h"

int main()
{
    printf("\n------------------------ WELCOME TO TicTacToe ------------------------\n");

    show_instructions();
    execute();

    return 0;
}

/* Room for improvement:
    1. let the player add their names and call them by it
    2. (another round?)
    3. Count how many times did X when for example
    4. alignment of the pipes '|' in the grid
    5. Better GUI
    6. Simplify grid printing logic
    7. Generalize win detection for cleaner logic

*/