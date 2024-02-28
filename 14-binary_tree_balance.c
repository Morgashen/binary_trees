#include "binary_trees.h" 

/**
 * binary_tree_height - Measures height of a binary tree 
 * @tree: Pointer to the root node of the tree to measure height
 * Return: Height of the tree, 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
  if (tree == NULL)
    return (0);

  size_t left_height = binary_tree_height(tree->left);
  size_t right_height = binary_tree_height(tree->right);

  if (left_height > right_height)
    return (left_height + 1);
  else 
    return (right_height + 1);
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure balance
 * Return: Balance factor (height of left - height of right), 0 if tree is NULL
*/ 
int binary_tree_balance(const binary_tree_t *tree) {

  if (tree == NULL)
    return (0);

  int left_height = binary_tree_height(tree->left);
  int right_height = binary_tree_height(tree->right);

  return (left_height - right_height);

}
