#ifndef GAME_FUNCS
#define GAME_FUNCS

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "nc_funcs.h"

void settings();
void setup_new_folder();
void main_game();
void draw_map(int player_x, int player_y, int view_x, int view_y, int map_x, int map_y, char * map);

#endif