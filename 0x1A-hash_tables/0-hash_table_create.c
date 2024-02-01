#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the array
 *
 * Return: A pointer to the newly created hash table,
 *         or NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *new_table = NULL;

    /* Allocate memory for the hash table structure */
    new_table = malloc(sizeof(hash_table_t));
    if (new_table == NULL)
        return (NULL);

    /* Allocate memory for the array of hash_node_t pointers */
    new_table->array = malloc(sizeof(hash_node_t *) * size);
    if (new_table->array == NULL)
    {
        free(new_table);
        return (NULL);
    }

    new_table->size = size;
    
    return (new_table);
}
