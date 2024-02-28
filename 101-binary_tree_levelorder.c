#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree 
 * Return: Height of the tree, 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree) {

  if (tree == NULL)
    return 0;

  size_t left_height = binary_tree_height(tree->left);
  size_t right_height = binary_tree_height(tree->right);

  return (left_height > right_height) ? left_height + 1 : right_height + 1;

}


/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure depth
 * Return: Depth of the node, 0 if tree is NULL  
*/
size_t binary_tree_depth(const binary_tree_t *tree) {
  
  size_t depth = 0;
  while (tree && tree->parent) {
    depth++;
    tree = tree->parent;
  }
  return depth;
}


/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal 
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * Return: Nothing, void function
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int)) {
  
  if (tree == NULL || func == NULL)
    return;

  for (size_t i = 0; i <= binary_tree_height(tree); i++) {
    print_level(tree, func, i); 
  }

}

/** 
 * print_level - Prints a given level of a binary tree  
 * @tree: A pointer to the root node of the tree to print the level for
 * @func: A pointer to the function to call for each node
 * @level: The level of the tree to print
*/
static void print_level(const binary_tree_t *tree, void (*func)(int), size_t level) {

 
  if (tree == NULL)
    return;
  
 
  if (level == 0) {
    func(tree->n);
    return;
  }

 
  print_level(tree->left, func, level - 1);
  print_level(tree->right, func, level - 1);

}
