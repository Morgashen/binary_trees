#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL, or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size) {

  if (!array || size == 0)
    return NULL;
  
  return construct_avl(array, 0, size - 1);

}


/**
 * construct_avl - Recursively constructs AVL tree from portion of array
 * @array: Array to construct tree from
 * @start: Starting index in array 
 * @end: Ending index in array
 *
 * Return: Pointer to root node of constructed AVL tree
*/
static avl_t *construct_avl(int *array, size_t start, size_t end) {

  if (start > end) 
    return NULL;

  size_t mid = (start + end) / 2;

  avl_t *node = binary_tree_node(NULL, array[mid]);
  node->left = construct_avl(array, start, mid - 1);
  node->right = construct_avl(array, mid + 1, end);

  return rebalance(node);
}
