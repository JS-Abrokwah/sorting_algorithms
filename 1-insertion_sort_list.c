#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * Definition for doubly-linked list.
 * struct listint_s {
 *     int n;
 *     struct listint_s *prev;
 *     struct listint_s *next;
 * };
 * typedef struct listint_s listint_t;
 */

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                        ascending order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;
    while (current != NULL) {
        listint_t *temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n) {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            temp->next = temp->prev;
            temp->prev = temp->next->prev;
            temp->next->prev = temp;
            if (temp->prev == NULL)
                *list = temp;
            else
                temp->prev->next = temp;
            printf("Current list: ");
            print_list(*list);
        }
        current = current->next;
    }
}

/**
 * print_list - Prints a doubly linked list of integers.
 * @list: Pointer to the head of the doubly linked list.
 */
void print_list(const listint_t *list)
{
    while (list != NULL) {
        printf("%d", list->n);
        if (list->next != NULL)
            printf(", ");
        list = list->next;
    }
    printf("\n");
}

