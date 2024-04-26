/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** ht_search.c
*/

#include "../../include/hashtable.h"

static char *search(hashtable_t *ht, char *key)
{
    int len_key = my_strlen(key);
    int _hash = ht->hash(key, len_key);
    int index = GET_INDEX(_hash, len_key, ht->max_index);
    h_index_t *current = ht->data[index]->index_ht;

    while (!current) {
        if (current->key == _hash)
            return current->data;
        current = current->next;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    if (!ht || !key || my_strlen(key) == 0)
        return NULL;
    return search(ht, key);
}
