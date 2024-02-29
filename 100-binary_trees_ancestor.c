#include "binary_trees.h"

/* Declare the hash function before using it */
int hash(binary_tree_t *node, int size);

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor;
	/* Create a hash table to store the ancestors of the first node */
	int size = 1024; /* You can choose a different size */
	binary_tree_t **table = malloc(sizeof(binary_tree_t *) * size);
	if (!table)
		return (NULL);
	/* Initialize the table with NULL values */
	for (int i = 0; i < size; i++)
		table[i] = NULL;
	/* Insert the ancestors of the first node into the table */
	ancestor = (binary_tree_t *)first;
	while (ancestor)
	{
		table[hash(ancestor, size)] = ancestor;
		ancestor = ancestor->parent;
	}
	/* Check if any ancestor of the second node is in the table */
	ancestor = (binary_tree_t *)second;
	while (ancestor)
	{
		if (table[hash(ancestor, size)] == ancestor)
		{
			/* Found the lowest common ancestor */
			break;
		}
		ancestor = ancestor->parent;
	}
	/* Free the table */
	free(table);
	/* Return the lowest common ancestor or NULL if not found */
	return (ancestor);
}

/* Define the hash function outside of the binary_trees_ancestor function */
int hash(binary_tree_t *node, int size)
{
	return ((unsigned long)node % size);
}
