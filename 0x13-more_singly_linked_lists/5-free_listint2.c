#include "lists.h"
/**
 * free_listint2 - function that free a linked list
 * @head: pointer to a pointer of a linked list
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *startElm, *nextElm;

	if (!head)
		return;
	startElm = *head;
	while (startElm)
	{
		nextElm = startElm->next;
		free(startElm);
		startElm = nextElm;
	}
	*head = NULL;
}
