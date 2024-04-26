/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** ht_delete.c
*/

#include "../../include/hashtable.h"

static void switch_link(h_index_t *current, h_index_t **begin)
{
    if (!current && !(*begin))
        return;
    if (current->prev == NULL || *begin == current)
        *begin = current->next;
    if (current->next)
        current->next->prev = current->prev;
    if (current->prev)
        current->prev->next = current->next;
}

static int delete(hashtable_t *ht, char *key)
{
    int len_key = my_strlen(key);
    int _hash = ht->hash(key, len_key);
    int index = GET_INDEX(_hash, len_key, ht->max_index);
    data_t **data = ht->data;
    h_index_t *current = data[index]->index_ht;

    while (current) {
        if (current->key == _hash) {
            switch_link(current, &ht->data[index]->index_ht);
            free(current);
            return 0;
        }
        current = current->next;
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    if (ht == NULL || key == NULL || my_strlen(key) == 0)
        return 84;
    return delete(ht, key);
}
