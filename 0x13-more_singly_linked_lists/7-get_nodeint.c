#include "lists.h"
/**
 * get_nodeint_at_index - func that returns the nth node of a linked list
 * @head: the linked list
 * @index: index of the node to be returned
 * Return: nth node of a linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *start;
	unsigned int i = 0;

	start = head;
	while (start)
	{
		if (i == index)
		{
			return (start);
		}
		start = head->next;
		i++;
	}
	return (NULL);
}
