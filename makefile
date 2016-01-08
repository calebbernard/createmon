default:
	gcc main.c dyn_tree.c nc_funcs.c game_funcs.c -lncurses -o createmon

clean:
	rm -f *.o createmon
