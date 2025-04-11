#include "binary_trees.h"


/**
 * binary_tree_rotate_left - A function that rotate left a binary tree
 *
 * @tree: A pointer to the tree to rotate
 *
 * Return: The new tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->right)
		return (tree);

	new_root = tree->right;
	tree->right = new_root->left;

	if (new_root->left)
		new_root->left->parent = tree;
	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}
