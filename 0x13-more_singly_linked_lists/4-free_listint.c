#include "lists.h"
/**
 * free_listint - function that frees a linked list
 * @head: pointer to a linked list
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *firstElem, *nextElem;

	if (!head)
		return;
	firstElem = head;
	while (firstElem)
	{
		nextElem = firstElem->next;
		free(firstElem);
		firstElem = nextElem;
	}
}
