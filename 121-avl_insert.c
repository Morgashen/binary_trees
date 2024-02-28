#include "binary_trees.h" 

/**
 * avl_insert - Inserts a node into an AVL tree
 * @tree: Double pointer to root node of AVL tree 
 * @value: Value to insert into the tree
 * Return: Pointer to inserted node, or NULL on failure
*/
avl_t *avl_insert(avl_t **tree, int value) {

  avl_t *new_node = NULL;

  if (*tree == NULL) {
    *tree = binary_tree_node(NULL, value);
    return (*tree);
  }

  new_node = r_avl_insert(*tree, NULL, value);

  return new_node;

}


/**
 * r_avl_insert - Recursive helper to insert into AVL tree
 * @root: Pointer to root node 
 * @parent: Pointer to parent node
 * @value: Value to insert
 * Return: Pointer to inserted node
*/
static avl_t *r_avl_insert(avl_t *root, avl_t *parent, int value) {

  if (root == NULL) {
    return (binary_tree_node(parent, value));
  }

  if (value < root->n) {
    root->left = r_avl_insert(root->left, root, value);
  } else if (value > root->n) {
    root->right = r_avl_insert(root->right, root, value);
  } else {
    return (root); 
  }

  root = rebalance(root);

  return root;

}


avl_t *rebalance(avl_t *root); 
avl_t *rotate_left(avl_t *root);
avl_t *rotate_right(avl_t *root);
