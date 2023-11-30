#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes_count = 0;
	int level_complete = 1;
	const binary_tree_t **queue;

	if (!tree)
		return (0);
	queue = malloc(sizeof(binary_tree_t *) * 10000);
	if (!queue)
		return (0);
	queue[0] = tree;
	nodes_count = 1;

	while (nodes_count > 0)
	{
		const binary_tree_t *temp = queue[0];

		if (!temp)
			break;
		if (!temp->left && temp->right)
			return (0);
		if (!level_complete && (temp->left || temp->right))
			return (0);
		if (temp->left)
			queue[nodes_count++] = temp->left;
		if (temp->right)
			queue[nodes_count++] = temp->right;
		if (temp->left || temp->right)
			level_complete = 0;
		nodes_count--;
		for (int i = 0; i < nodes_count; i++)
			queue[i] = queue[i + 1];
	}
	free(queue);
	return (1);
}
