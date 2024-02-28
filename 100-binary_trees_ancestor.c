#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds lowest common ancestor of two nodes 
 * @first: Pointer to first node
 * @second: Pointer to second node
 * Return: Pointer to common ancestor, or NULL if none found or invalid input
*/
const binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, 
                                           const binary_tree_t *second)
{
  if (first == NULL || second == NULL)
    return (NULL);

  if (first == second) 
    return (first);

  const binary_tree_t *p = first->parent;
  const binary_tree_t *q = second->parent;

  while (p != NULL && q != NULL) {
    if (p == q)
      return (p);
    p = p->parent;
    q = q->parent; 
  }

  return (NULL);
}
