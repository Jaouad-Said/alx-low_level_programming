#include "lists.h"
/**
 * sum_listint - function that returns the sum of all data in a linked list
 * @head: the pointer to the linked list
 * Return: int
 */
int sum_listint(listint_t *head)
{
	listint_t *first;
	int sum = 0;

	if (!head)
		return (0);
	first = head;
	while (first)
	{
		sum = sum + first->n;
		first = first->next;
	}
	return (sum);
}
