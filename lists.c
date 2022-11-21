#include "list.h"
/**
 * print_list - prints linked list to stdout
 * @head: head node of liinked list
 * @str: string data of node
 * @year: integer data of node
 * Return: number of nodes printed 
 */
size_t print_list(list_t *head)
{
	list_t *temp;
	size_t count;

	temp = head;
	
	count = 0;
	while (temp != NULL)
	{
		if (temp->name == NULL)
			printf("(0): nil\n");
		else
			printf("[Node-Name] => %s, [Year] => %d\n", 
					temp->name, temp->year);
		temp = temp->next;
		count++;
	}

	return (count);
}
/**
 * add_node - add node to the head of the list
 * @str: name data to add
 * @year: year data to add
 * Return: pointer to head node
 */
list_t *add_node(list_t **head, char *name, int year)
{
	list_t *newnode;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);

	newnode->name = strdup(name);
	newnode->year = year;

	newnode->next = *head;

	*head = newnode;

	return (*head);
}
/**
 * add_node_end - adds a node at the end
 * @head: head of node
 * @name: name data
 * @year: year data
 * Return: pointer to node added
 */
list_t *add_node_end(list_t **head, char *name, int year)
{
	list_t *temp;
	list_t *newnode;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);

	newnode->name = strdup(name);
	if (newnode->name == NULL)
	{
		free(newnode->name);
		free(newnode);
		return (NULL);
	}
	newnode->year = year;
	newnode->next = NULL;

	if ((*head) == NULL)
	{
		*head = newnode;
		return (newnode);
	}

	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newnode;

	return (newnode);

}
/**
 * main - entry point
 *
 * Return: always 0
 */
int main(void)
{
	list_t *head;
	list_t *temp;
	size_t n;
	
	head = NULL;

	add_node(&head, "Taiwo", 1776);
	add_node(&head, "Mike", 1345);
	add_node(&head, "Tomisin", 1454);
	add_node(&head, "OLuwASEGUN", 346);
	
	n = print_list(head);

	printf("=> %lu elements\n", n);

	temp = head;
	while (temp)
	{
		free(temp->name);
		free(temp);

		temp = temp->next;
	}

	add_node_end(&head, "Taiwo", 1776);
	add_node_end(&head, "Mike", 1345);
	add_node_end(&head, "Tomisin", 1454);
	add_node_end(&head, "OluwASEGUN", 1776);

	n = print_list(head);
	printf("=> %lu elements\n", n);

	temp = head;

	while (temp)
	{
		free(temp->name);
		free(temp);

		temp = temp->next;
	}
	return (0);
}
