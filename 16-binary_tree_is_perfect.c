#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure height
 * Return: Height of the tree, or 0 if tree is NULL
*/  
size_t binary_tree_height(const binary_tree_t *tree) {

  if (tree == NULL)
    return 0;

  size_t left_height = binary_tree_height(tree->left);
  size_t right_height = binary_tree_height(tree->right);

  if (left_height > right_height) {
    return left_height + 1;
  } else {  
    return right_height + 1;
  }

}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise or if tree is NULL
*/
int binary_tree_is_perfect(const binary_tree_t *tree) {
  
  if (tree == NULL)
    return 0;

  int left_height = binary_tree_height(tree->left);
  int right_height = binary_tree_height(tree->right);

  if (left_height == right_height && left_height != 0)
    return 1;

  return 0;

}
