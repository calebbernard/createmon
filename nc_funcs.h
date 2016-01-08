#ifndef NC_FUNCS
#define NC_FUNCS

#include <stdio.h>
#include <ncurses.h>
#include <string.h>

void center_print(int y, char * msg);
void line_input(int y, char * input, int input_size);
void print_menu(char ** options, int num_options, int highlight, int first_print, int last_print);
int menu(char ** options, int num_options);

#endif