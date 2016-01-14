#include "game_funcs.h"
#include "nc_funcs.h"

void settings(){
  char * options[] = {
    "Map", "Types", "Statuses", "Monsters", "Items", "Moves", "Return"
  };
  int num_options = 7;
  char hey[15];
  sprintf(hey, "%d", num_options);
  int choice = menu(options, num_options);
  while (choice != (num_options - 1)){
    // put individual menus here
    center_print(1, "Here");
    char ch = getch();
    choice = menu(options, num_options);
  }
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
  fprintf(fp, "%s\n%s", game_name, "map/1");
  
  char * folders[] = {
    "map", "type", "status", "monster", "item", "move", "save"
  };
  int x;
  int num_folders = 7;
  for (x = 0; x < num_folders; x++){
    mkdir (folders[x], S_IRWXU);
  }
  fclose(fp);
  fp = fopen("map/1", "w");
  fprintf(fp, "%s", "8 8\n1(64)");
  fclose(fp);
  settings();
}

void draw_map(int player_x, int player_y, int view_x, int view_y, int map_x, int map_y, char * map){
  clear();
  int right_x = view_x / 2;
  int left_x = view_x / 2 - 1;
  int top_y = view_y / 2;
  int bottom_y = view_y / 2 - 1;
  int x,y;
  char tile;
  int drawing_x, drawing_y;
  for (x = 0; x < view_x; x++){
    for (y = 0; y < view_y; y++){
      if (player_x - left_x + x < 0){
       tile = ' ';
      } else if (player_x + right_x + x >= map_x){
        tile = ' ';
      } else if (player_y - top_y + y < 0){
        tile = ' ';
      } else if (player_y + bottom_y + y >= map_y){
        tile = ' ';
      } else {
        int col = player_x - left_x + x;
        int row = player_y - top_y + y;
        tile = map[row * map_x + col];
      }
      mvaddch(y, x, tile);
    }
  }
}

void main_game(){
  FILE * fp = fopen("init", "r");
  char game_name[128];
  char current_room[128];
  int view_x, view_y;
  fscanf(fp, "%s %s %d %d", &game_name, &current_room, &view_x, &view_y);
  fclose(fp);
  char room_path[156];
  strcpy(room_path, "map/");
  strcat(room_path, current_room);
  
  //center_print(1, room_path);
  //refresh();
  fp = fopen(room_path, "r");
  int x, y, area, player_x, player_y;
  player_x = 0;
  player_y = 0;
  fscanf(fp, "%d %d", &x, &y);
  area = x * y;
  char * map;
  
  map = malloc(area * sizeof(char));
  int z;
  for (z = 0; z < x; z++){
    fscanf(fp, "%s", &map[x*z]);
  }
  fclose(fp);
    
  draw_map(player_x, player_y, view_x, view_y, x, y, map);
  

  
}