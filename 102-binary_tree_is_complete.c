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
 * binary_tree_is_complete - A function that checks if a binary tree
 *								is complete
 *
 * @tree: A pointer to the tree to check
 *
 * Return: 0 if not complete, 1 if complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_node_t *queue = NULL;
	const binary_tree_t *current;
	int flag = 0;

	if (!tree)
		return (0);

	enqueue(&queue, tree);
	while (queue)
	{
		current = dequeue(&queue);
		if (current->left == NULL && current->right != NULL)
			return (0);

		if (current->left)
			enqueue(&queue, current->left);
		if (current->right)
			enqueue(&queue, current->right);
		else
			flag = 1;

		if (flag && (current->left || current->right))
			return (0);
	}
	return (1);
}
