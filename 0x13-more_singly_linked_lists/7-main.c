#include "lists.h"
/**
 * pop_listint - function that deletes the head node a linked list
 * @head: pointer that points to a linked list
 * Return: int
 */
int pop_listint(listint_t **head)
{
	listint_t *newN;
	int n;

	if (!head || !*head)
		return (0);
	newN = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = newN;
	return (n);
}
