#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a binary search tree
 * @root: Pointer to root node of BST 
 * @value: Value to remove from BST
 * Return: Pointer to new root node of BST after removal
*/  
bst_t *bst_remove(bst_t *root, int value) {

  if (root == NULL)
    return NULL;

  if (value < root->n) {
    root->left = bst_remove(root->left, value);
  } else if (value > root->n) {  
    root->right = bst_remove(root->right, value);
  } else {

    if (root->left == NULL) {
      bst_t *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      bst_t *temp = root->left;
      free(root);
      return temp;
    }

    bst_t *temp = find_min(root->right);
    root->n = temp->n;
    root->right = bst_remove(root->right, temp->n);
  }

  return root;
}

/**
 * find_min - Finds minimum node in binary search tree
 * @root: Root node of BST to search 
 * Return: Pointer to node with min value
*/
static bst_t *find_min(bst_t *root) {
  bst_t *curr = root;
  while (curr->left != NULL) {
    curr = curr->left;
  }
  return curr;
}
