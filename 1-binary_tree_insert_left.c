#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - A function that insert a node at left
 *
 * @parent: Is a pointer to the node that insert the left-child in
 * @value: Is the value to store in new node
 *
 * Return: A pointer to the new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	if (parent == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;

	if (parent->left == NULL)
	{
		parent->left = new_node;
		new_node->left = NULL;
	}
	else
	{
		new_node->left = parent->left;
		new_node->left->parent = new_node;
		parent->left = new_node;
	}

	return (new_node);
}
