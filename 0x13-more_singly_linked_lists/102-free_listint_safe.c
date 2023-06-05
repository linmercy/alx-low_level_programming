#include <stdlib.h>
#include "lists.h"
/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow = *h;
	listint_t *fast = *h;
	size_t count = 0;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = *h;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			while (fast->next != slow)
				fast = fast->next;
			while (fast->next != slow)
			{
				fast = fast->next;
				free(slow);
				count++;
				slow = fast->next;
			}
			free(slow);
			count++;
			*h = NULL;
			return (count);
		}
	}
	while (*h != NULL)
	{
		slow = *h;
		*h = (*h)->next;
		free(slow);
		count++;
	}
	return (count);
}
