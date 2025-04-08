#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_insert_right - A function that insert a node in the right
 *								child position
 *
 * @parent: A pointer to the node parent
 * @value: The value to store in the noew node
 *
 * Return: A pointer to the new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	if (parent == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (parent->right == NULL)
	{
		parent->right = new_node;
		new_node->right = NULL;
	}

	else
	{
		new_node->right = parent->right;
		new_node->right->parent = new_node;
		parent->right = new_node;
	}

	new_node->left = NULL;
	new_node->n = value;
	new_node->parent = parent;

	return (new_node);
}
