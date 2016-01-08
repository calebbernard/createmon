#include "dyn_tree.h"

struct dyn_tree {
  int size;
  int capacity;
  struct dyn_tree ** data;
};

void dyn_tree_init(struct dyn_tree * dt){
  dt->size = 0;
  dt->capacity = 64;
  dt->data = malloc(sizeof(struct dyn_tree) * dt->capacity);
}

void dyn_tree_set(struct dyn_tree * dt, int index, struct dyn_tree * leaf){
  dt->data[index] = leaf;
}

void dyn_tree_add(struct dyn_tree * dt, struct dyn_tree * leaf){
  if (dt->size == dt->capacity){
    dt->capacity *= 2;
    dt->data = realloc(dt->data, sizeof(struct dyn_tree) * dt->capacity);
  }
  dyn_tree_set(dt, dt->size, leaf);
  dt->size++;
}

void dyn_tree_free(struct dyn_tree * dt){
  free(dt->data);
}