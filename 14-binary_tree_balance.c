#include "binary_trees.h"


/**
 * binary_tree_h - A function that measures the height of a binary tree
 *
 * @tree: A pointer to the tree to measure
 *
 * Return: The height of the binary tree, 0 if NULL
 */

size_t binary_tree_h(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);


	left_h = binary_tree_h(tree->left);
	right_h = binary_tree_h(tree->right);

	return (1 + (left_h > right_h ? left_h : right_h));
}


/**
 * binary_tree_balance - A function that measures the balance factor of a btree
 *
 * @tree: A pointer to the root of the tree
 *
 * Return: The balance of the tree or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_h(tree->left);
	right_h = binary_tree_h(tree->right);

	return (left_h - right_h);
}
