#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

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
    listint_t *left = NULL, *right = NULL, *curr = NULL;
    int swapped = 0;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        for (left = *list; left->next != NULL; left = left->next) {
            if (left->n > left->next->n) {
                swap_nodes(list, left, left->next);
                swapped = 1;
                print_list(*list);
            }
        }
        if (swapped == 0)
            break;
        swapped = 0;
        for (right = left->prev; right != NULL; right = right->prev) {
            if (right->prev == NULL)
                break;
            if (right->n < right->prev->n) {
                swap_nodes(list, right->prev, right);
                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 *
 * @list: pointer to pointer to the head of the doubly linked list
 * @node1: pointer to the first node to be swapped
 * @node2: pointer to the second node to be swapped
 *
 * Return: void
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *temp1 = NULL, *temp2 = NULL;

    if (node1 == NULL || node2 == NULL)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;
    temp1 = node1->prev;
    temp2 = node2->next;
    node2->next = node1;
    node1->prev = node2;
    node1->next = temp2;
    node2->prev = temp1;
}

