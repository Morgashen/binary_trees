#include "binary_trees.h"

/**
 * binary_tree_height - Measures height of a binary tree
 * @tree: Pointer to root node
 * Return: Height of tree, 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree) {

  if (tree == NULL)
    return 0;

  size_t left_height = binary_tree_height(tree->left);
  size_t right_height = binary_tree_height(tree->right);
  
  return (left_height > right_height) ? left_height + 1 : right_height + 1;

}


/**
 * binary_tree_is_avl - Checks if a binary tree is valid AVL tree
 * @tree: Pointer to root node
 * Return: 1 if valid AVL, 0 otherwise or if NULL
*/ 
int binary_tree_is_avl(const binary_tree_t *tree) {

  if (tree == NULL)
    return 0;
    
  int balance = binary_tree_balance(tree);

  if (abs(balance) > 1)
    return 0;

  return (binary_tree_is_avl(tree->left) && 
          binary_tree_is_avl(tree->right)); 

}


/**
 * binary_tree_balance - Gets balance factor of a node
 * @tree: Node to get balance factor of
 * Return: Balance factor 
*/
int binary_tree_balance(const binary_tree_t *tree) {

  if (tree == NULL)
    return 0;

  int left_height = binary_tree_height(tree->left);
  int right_height = binary_tree_height(tree->right);

  return left_height - right_height;

}
