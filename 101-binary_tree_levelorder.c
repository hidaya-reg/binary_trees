#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1000);
	int front = 0, rear = 0;
	const binary_tree_t *temp = tree;

	if (!tree || !func)
		return;
	if (!tree)
		return;
	if (!queue)
		return;

	while (temp)
	{
		func(temp->n);
		if (temp->left)
			queue[rear++] = (binary_tree_t *)temp->left;
		if (temp->right)
			queue[rear++] = (binary_tree_t *)temp->right;
		temp = queue[front++];
	}
	free(queue);
}
