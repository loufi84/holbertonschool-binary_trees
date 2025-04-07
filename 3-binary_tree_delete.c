#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Delete a whole binary tree
 *
 * @tree: The tree to delete
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
