#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stdbool.h>

void swap_node_ahead(listint_t **list, listint_t **node1, listint_t **node2);
void swap_node_behind(listint_t **list, listint_t **node1, listint_t **node2);
/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *                      in ascending order using Cocktail shaker sort
 *
 * @list: pointer to pointer to the head of the doubly linked list
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node1, *node2;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	for (node1 = *list; node1->next != NULL; node1 = node1->next)

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (node2 = *list; node2 != node1; node2 = node2->next)
		{
			if (node2->n > node2->next->n)
			{
				swap_node_ahead(list, &node1, &node2);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (node2 = node2->prev; node2 != *list;
				node2 = node2->prev)
		{
			if (node2->n < node2->prev->n)
			{
				swap_node_behind(list, &node1, &node2);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
/**
 * swap_node_a - swaps two nodes in a doubly linked list
 *
 * @list: pointer to pointer to the head of the doubly linked list
 * @node1: pointer to the first node to be swapped
 * @node2: pointer to the second node to be swapped
 *
 * Return: void
 */
void swap_node_ahead(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *tmp = (*node2)->next;

	if ((*node2)->prev != NULL)
		(*node2)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*node2)->prev;
	(*node2)->next = tmp->prev;
	if (tmp->next != NULL)
		tmp->next->prev = *node2;
	else
		*node1 = *node2;
	(*node2)->prev = tmp;
	tmp->next = *node2;
	*node2 = tmp;
}
/**
 * swap_node_b - swaps a node in a doubly-linked list with the node behind
 * @list: pointer to the head of the doubly linked list
 * @node1: pointer to the tail
 * @node2: pointer to the current swapping node
 */
void swap_node_behind(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *tmp = (*node2)->prev;

	if ((*node2)->next != NULL)
		(*node2)->next->prev = tmp;
	else
		*node1 = tmp;
	tmp->next = (*node2)->next;
	(*node2)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *node2;
	else
		*list = *node2;
	(*node2)->next = tmp;
	tmp->prev = *node2;
	*node2 = tmp;
}
