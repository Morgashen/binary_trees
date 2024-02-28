#include "binary_trees.h" 

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if BST, 0 if not or if tree is NULL
*/
int binary_tree_is_bst(const binary_tree_t *tree) {

  if (tree == NULL)
    return (0);

  return (bst_check(tree, INT_MIN, INT_MAX));

}

/**
 * bst_check - Recursive helper to check subtrees are valid BST
 * @node: Current node to check 
 * @min: Minimum allowed value in subtree
 * @max: Maximum allowed value in subtree
 * Return: 1 if valid BST, 0 if not
*/
int bst_check(const binary_tree_t *node, int min, int max) {

  if (node == NULL)
    return (1);

  if (node->n < min || node->n > max)
    return (0);

  return (bst_check(node->left, min, node->n - 1) && 
          bst_check(node->right, node->n + 1, max));
  
}
