#include "game_funcs.h"
#include "nc_funcs.h"

void settings(){
  char * options[] = {
    "Map", "Types", "Statuses", "Monsters", "Items", "Return"
  };
  int num_options = 6;
  char hey[15];
  sprintf(hey, "%d", num_options);
    //center_print(1, hey);
  int choice = menu(options, num_options);
}

void setup_new_folder(){
  clear();
  char game_name[128];
  FILE * fp = fopen("init", "w");
  // Perhaps add validation here

  int y = LINES / 2;
  center_print(y, "Enter a name for the game:");
  refresh();
  y++;
  line_input(y, game_name, 128);
  fprintf(fp, "%s\n", game_name);
  mkdir("map", S_IRWXU);
  mkdir("type", S_IRWXU);
  mkdir("status", S_IRWXU);
  mkdir("monster", S_IRWXU);
  mkdir("item", S_IRWXU);
  fclose(fp);
  settings();
}