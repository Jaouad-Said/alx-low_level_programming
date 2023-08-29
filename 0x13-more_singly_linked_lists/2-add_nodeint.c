#include "lists.h"
/**
 * add_nodeint - function that adds a node at the begining of a linekd list
 * @head: pointer to a pointer of a linked list
 * @n: data of the node
 * Return: the adress of a node or null
 */
listint_t *add_nodint(listint_t **head, const int n)
{
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = n;
	newNode->next = *head;
	*head = newNode;
	return (newNode);
}
