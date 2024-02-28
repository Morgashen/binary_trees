#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid max heap
 * @tree: Pointer to the root node of tree to check 
 * Return: 1 if valid max heap, 0 otherwise
*/
int binary_tree_is_heap(const binary_tree_t *tree) {

  if (!tree)
    return (0);
  
  return (is_max_heap(tree, INT_MAX)); 

}

/**
 * is_max_heap - Recursive check that subtree is max heap
 * @node: Root node of subtree
 * @max: Maximum allowed value
 * Return: 1 if valid max heap, 0 otherwise
*/
int is_max_heap(const binary_tree_t *node, int max) {

  if (!node)
    return (1);

  int left_valid = is_max_heap(node->left, node->n);
  int right_valid = is_max_heap(node->right, node->n);

  return (node->n <= max && left_valid && right_valid);

}
