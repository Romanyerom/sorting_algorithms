#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the doubly linked list.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail Shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL, *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
            {
		    swap_nodes(list, &start, start->next);
		    print_list((const listint_t *)*list);
		    swapped = 1;
	    }
		}

		if (!swapped)
			break;

		swapped = 0;
		for (end = start; end != *list; end = end->prev)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(list, &end, end->prev);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	}
}
