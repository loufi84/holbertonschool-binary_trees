#include "binary_trees.h"

/**
 * binary_trees_ancestor - A function that find the lowest ancestor of 2 nodes
 *
 * @first: The first node to check
 * @second: The second node to check
 *
 * Return: A pointer to the lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	const binary_tree_t *tmp1, *tmp2;

	if (!first || !second)
		return (NULL);

	tmp1 = first;
	while (tmp1)
	{
		tmp2 = second;
		while (tmp2)
		{
			if (tmp1 == tmp2)
				return ((binary_tree_t *)tmp1);
			tmp2 = tmp2->parent;
		}
		tmp1 = tmp1->parent;
	}
	return (NULL);
}
