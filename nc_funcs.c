#include "nc_funcs.h"


void center_print(int y, char * msg){
  mvprintw(y, (COLS - strlen(msg)) / 2, msg);
}

void line_input(int y, char * input, int input_size){
  char ch;
  int size = 0;
  memset(input, 0, input_size);
  while (size < input_size){
    ch = getch();
    if (ch == '\n'){
      input[size] = '\0';
      break;
    } else {
      input[size] = ch;
      size++;
    }
    center_print(y, input);
    refresh();
  }
}

void print_menu(char ** options, int num_options, int highlight, int first_print, int last_print){
  clear();
  int y = 1;
  int iter;
  for (iter = first_print; iter < last_print; iter++){
    if (highlight == iter){
      attron(A_REVERSE);
      center_print(y, options[iter]);
      attroff(A_REVERSE);
    } else {
      center_print(y, options[iter]);
    }
    y++;
  }
  
}

int menu(char ** options, int num_options){
  int choice = -1;
  int highlight = 0;
  int ch;
  int too_big = 0;
  int first_print = 0;
  int last_print = num_options;
  if (num_options >= LINES){
    last_print = LINES - 1;
    too_big = 1;
  }

  while (choice == -1){
    print_menu(options, num_options, highlight, first_print, last_print);
    ch = getch();
    if (ch == KEY_UP){
      if (highlight == 0){
        highlight = num_options - 1;
        if (too_big){
          last_print = num_options;
          first_print = (last_print - LINES) + 1;
        }
      } else {
        highlight--;
        if (too_big){
          if (highlight == first_print){
            first_print--;
            last_print--;
          }
        }
      }
    }
    if (ch == KEY_DOWN){
      if (highlight == num_options - 1){
        highlight = 0;
        if (too_big){
          first_print = 0;
          last_print = LINES - 1;
        }
      } else {
        highlight++;
        if (too_big){
          if (highlight == last_print){
            first_print++;
            last_print++;
          }
        }
      }
    }
    // 10 is enter
    if (ch == 10){
      choice = highlight;
    }
  }
  clear();
  return choice;
}