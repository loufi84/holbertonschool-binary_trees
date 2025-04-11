#include "binary_trees.h"

/**
 * binary_tree_rotate_right - A function that rotate a binary tree to the right
 *
 * @tree: A pointer to the tree to rotate
 *
 * Return: The new tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->left)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;

	if (new_root->right)
		new_root->right->parent = tree;
	new_root->right = tree;
	tree->parent = new_root;

	return (new_root);
}
