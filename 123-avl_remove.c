#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to root node of AVL tree
 * @value: Value to remove from tree
 * Return: Pointer to new root node after removal  
*/
avl_t *avl_remove(avl_t *root, int value) {

  if (root == NULL)
    return NULL;

  root = remove_node(root, value);
  
  return rebalance(root);

}

/** 
 * remove_node - Removes node from BST  
 * @root: Root of BST
 * @value: Value to remove
 * Return: Pointer to new root after removal
*/
static avl_t *remove_node(avl_t *root, int value) {

  if (value < root->n) {
    root->left = remove_node(root->left, value);
  } else if (value > root->n) {
    root->right = remove_node(root->right, value); 
  } else {

    if (root->left == NULL) {
      avl_t *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      avl_t *temp = root->left;
      free(root);
      return temp;
    }


    avl_t *temp = find_successor(root->right);
    root->n = temp->n;
    root->right = remove_node(root->right, temp->n);
  }

  return root;
}

/**
 * find_successor - Finds in-order successor of a node
 * @root: Root of BST to search  
 * Return: Pointer to successor node
*/ 
static avl_t *find_successor(avl_t *root) {

  avl_t *curr = root;
  while (curr->left != NULL) {
    curr = curr->left;
  }
  return curr;
}


avl_t *rebalance(avl_t *root);
