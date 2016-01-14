#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "nc_funcs.h"
#include "dyn_tree.h"
#include "game_funcs.h"

// Thanks to http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html for ncurses examples


int main(){
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	
	char ch;
	int y, x;
	
	char folder[128];
	
	int center_y = LINES / 2;
  int center_x = COLS / 2;
	
	// A little above center
	y = center_y - 5;
	
	center_print(y, "Calebmon");
	y += 2;
	center_print(y, "Enter a game folder:");
	refresh();
	y++;
	line_input(y, folder, 128);
	refresh();
  while (chdir(folder)){
    clear();
    center_print(y, "Make a new game folder? (y/n)");
    refresh();
    ch = getch();
    if (ch == 'y'){
      mkdir(folder, S_IRWXU);
    } else {
      clear();
      center_print(y, "Enter a game folder:");
      refresh();
      y++;
      line_input(y, folder, 128);
      y--;
    }
    refresh();
  }
  
  clear();
  
  FILE * fp;
  
  fp = fopen("init", "r");
  if (fp == NULL){
    setup_new_folder();
    fp = fopen("init", "r");
  }
  fclose(fp);
  main_game();
  
  
	refresh();
	getch();
	endwin();
	return 0;
}