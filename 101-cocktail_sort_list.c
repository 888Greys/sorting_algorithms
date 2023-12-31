#include "sort.h"

/**
* swap_node_ahead - Swaps a node in a doubly-linked list
*with the node ahead of it.
*
* This function swaps the specified node in a
*doubly-linked list, represented
* by the @shaker pointer, with the node immediately
*ahead of it. The function
* updates the list head and tail as necessary and
*prints the list after the swap.
*
* @list: A pointer to the head of a doubly-linked
*list of integers.
* @tail: A pointer to the tail of the doubly-linked
*list.
* @shaker: A pointer to the current swapping node of
*the cocktail shaker algorithm.
*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->next;

if ((*shaker)->prev != NULL)
(*shaker)->prev->next = tmp;
else
*list = tmp;
tmp->prev = (*shaker)->prev;
(*shaker)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *shaker;
else
*tail = *shaker;
(*shaker)->prev = tmp;
tmp->next = *shaker;
*shaker = tmp;
print_list((const listint_t *)*list);
}

/**
* swap_node_behind - Swaps a node in a doubly-linked
*list with the node behind it.
*
* This function swaps the specified node in a
*doubly-linked list, represented
* by the @shaker pointer, with the node
*immediately behind it. The function
* updates the list head and tail as necessary
*and prints the list after the swap.
*
* @list: A pointer to the head of a
*doubly-linked list of integers.
* @tail: A pointer to the tail of the
*doubly-linked list.
* @shaker: A pointer to the current swapping
*node of the cocktail shaker algorithm.
*/
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->prev;

if ((*shaker)->next != NULL)
(*shaker)->next->prev = tmp;
else
*tail = tmp;
tmp->next = (*shaker)->next;
(*shaker)->prev = tmp->prev;
if (tmp->prev != NULL)
tmp->prev->next = *shaker;
else
*list = *shaker;
(*shaker)->next = tmp;
tmp->prev = *shaker;
*shaker = tmp;
print_list((const listint_t *)*list);
}

/**
* cocktail_sort_list - Sorts a doubly-linked list
*of integers in ascending order
*                      using the cocktail shaker algorithm.
*
* This function sorts the given doubly-linked
*list of integers, represented by the
* @list pointer, in ascending order using the
*cocktail shaker algorithm. It updates
* the list head and tail as necessary and
*prints the list after each swap.
*
* @list: A pointer to the head of a
*doubly-linked list of integers.
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
bool shaken_not_stirred = false;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (tail = *list; tail->next != NULL;)
tail = tail->next;

while (!shaken_not_stirred)
{
shaken_not_stirred = true;
for (shaker = *list; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n)
{
swap_node_ahead(list, &tail, &shaker);
shaken_not_stirred = false;
}
}
for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
{
if (shaker->n < shaker->prev->n)
{
swap_node_behind(list, &tail, &shaker);
shaken_not_stirred = false;
}
}
}
}
