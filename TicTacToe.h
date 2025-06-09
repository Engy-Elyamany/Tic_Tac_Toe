#ifndef TIC_TAC_TOE_h
#define TIC_TAC_TOE_h

#include <stdio.h>
#define first_player_char 'X'
#define second_player_char 'O'

static char grid[9] = {' '};

void print_grid(char arr[]);
void show_instructions();
int unique_pos(int pos);
char *populate_grid(int pos, char c);
int check_rows(char *gptr, char val);
int check_cols(char *gptr, char val);
int check_diagonal(char *gptr, char val);
int winning_algorithm(char *gptr);
void execute();

#endif