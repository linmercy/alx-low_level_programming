#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Double pointer to the head of the list.
 *
 * Return: The data stored in the head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    listint_t *temp;
    int data = 0;

    if (head != NULL && *head != NULL)
    {
        temp = *head;
        data = temp->n;
        *head = temp->next;
        free(temp);
    }

    return (data);
}

