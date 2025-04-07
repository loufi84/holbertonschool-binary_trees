#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - A function that create a new node in a binary tree
 *
 * @parent: The pointer to the parent node
 * @value: The value in the new node
 *
 * Return: The pointer to the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;

	return (new_node);
}
