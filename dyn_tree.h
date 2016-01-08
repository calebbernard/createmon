#ifndef DYN_TREE
#define DYN_TREE

#include <stdlib.h>

struct dyn_tree;
void dyn_tree_init(struct dyn_tree * dt);
void dyn_tree_set(struct dyn_tree * dt, int index, struct dyn_tree * leaf);
void dyn_tree_add(struct dyn_tree * dt, struct dyn_tree * leaf);
void dyn_tree_free(struct dyn_tree * dt);

#endif