#include "binary_trees.h"

/**
 * enqueue - A function that create a queue for binary trees
 *
 * @head: A pointer to the head of the list
 * @node: A pointer to the current node
 */

void enqueue(queue_node_t **head, const binary_tree_t *node)
{
	queue_node_t *tmp, *new = malloc(sizeof(queue_node_t));

	if (!new)
		return;

	new->node = node;
	new->next = NULL;

	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/**
 * dequeue - A function that un-queue a node
 *
 * @head: The head of the list
 *
 * Return: A pointer to the queue
 */

const binary_tree_t *dequeue(queue_node_t **head)
{
	queue_node_t *tmp;
	const binary_tree_t *node;

	if (!head || !*head)
		return (NULL);
	tmp = *head;
	node = tmp->node;
	*head = tmp->next;
	free(tmp);
	return (node);
}

/**
 * binary_tree_levelorder - A function that trasverse a binary tree
 *							in level order
 *
 * @tree: A pointer to the tree to trasverse
 * @func: A pointer to the function to use
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_node_t *queue = NULL;
	const binary_tree_t *current;

	if (!tree || !func)
		return;

	enqueue(&queue, tree);

	while (queue)
	{
		current = dequeue(&queue);
		func(current->n);

		if (current->left)
			enqueue(&queue, current->left);
		if (current->right)
			enqueue(&queue, current->right);
	}
}
