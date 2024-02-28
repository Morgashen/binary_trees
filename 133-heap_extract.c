#include "binary_trees.h"

/**
 * heap_extract - Extracts root node from max binary heap
 * @root: Double pointer to root of heap
 * Return: Value stored in root node, or 0 if fail
*/ 
int heap_extract(heap_t **root) {

  if (!root || !*root)
    return 0;

  heap_t *node = *root;
  int value = node->n;

 
  if (!node->left && !node->right) {
    *root = NULL;
    free(node);
    return value;
  }


  heap_t *last = get_last_node(*root);
  node->n = last->n;

 
  detach_node(last);
  free(last);

 
  heapify_down(node);

  return value;
}


/**
 * get_last_node - Finds the last node in heap
 * @root: Root of heap
 * Return: Pointer to last node
*/
static heap_t *get_last_node(heap_t *root) {

  heap_t *curr = root;
  while (curr->right) {
    curr = curr->right;
  }
  return curr;
}


void detach_node(heap_t *node);
void heapify_down(heap_t *node);
