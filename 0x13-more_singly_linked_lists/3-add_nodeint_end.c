#include "lists.h"
/**
 * add_nodeint_end - function that add a node at te end of a linked list
 * @head: pointer to a pointer of a linked list
 * @n: data of created node
 * Return: the address of the new element or null
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode, *lastNode;

	lastNode = *head;
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = n;
	newNode->next = NULL;

	if (lastNode == NULL)
	{
		*head = newNode;
		return (newNode);
	}
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
	return (newNode);
}
