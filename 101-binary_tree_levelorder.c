#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	const binary_tree_t *temp = tree;
	binary_tree_t **queue;

	if (!tree || !func)
		return;
	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (!queue)
		return;

	queue[rear++] = (binary_tree_t *)temp;
	while (front < rear)
	{
		temp = queue[front++];
		func(temp->n);
		if (temp->left)
			queue[rear++] = (binary_tree_t *)temp->left;
		if (temp->right)
			queue[rear++] = (binary_tree_t *)temp->right;
	}
	free(queue);
}
