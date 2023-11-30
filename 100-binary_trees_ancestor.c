#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *temp_1 = first, *temp_2 = second;
	size_t depth_1 = 0, depth_2 = 0;

	if (!first || !second)
		return (NULL);

	while (temp_1->parent)
	{
		temp_1 = temp_1->parent;
		depth_1++;
	}

	while (temp_2->parent)
	{
		temp_2 = temp_2->parent;
		depth_2++;
	}
	temp_1 = first;
	temp_2 = second;
	while (depth_1 > depth_2)
	{
		temp_1 = temp_1->parent;
		depth_1--;
	}
	while (depth_2 > depth_1)
	{
		temp_2 = temp_2->parent;
		depth_2--;
	}
	while (temp_1 && temp_2)
	{
		if (temp_1 == temp_2)
			return ((binary_tree_t *)temp_1);
		temp_1 = temp_1->parent;
		temp_2 = temp_2->parent;
	}
	return (NULL);
}
