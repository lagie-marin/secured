/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** ht_insert.c
*/

#include "../../include/hashtable.h"

static h_index_t *get_current_index(h_index_t *begin, int _hash)
{
    h_index_t *current = begin;

    if (current == NULL)
        return NULL;
    while (current->next && current->key != _hash)
        current = current->next;
    return current;
}

static void new_instert(hashtable_t *ht, char *key, char *value, int len_key)
{
    int _hash = ht->hash(key, len_key);
    int index = GET_INDEX(_hash, len_key, ht->max_index);
    h_index_t *current = get_current_index(ht->data[index]->index_ht, _hash);
    h_index_t *new;

    if (current && current->key == _hash) {
        current->data = value;
        return;
    }
    new = malloc(sizeof(h_index_t));
    new->key = _hash;
    new->data = value;
    new->index = index;
    new->prev = current;
    new->next = NULL;
    if (current)
        current->next = new;
    else
        ht->data[index]->index_ht = new;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    if (!ht || !key || !value)
        return 84;
    if (my_strlen(key) == 0 || my_strlen(value) == 0)
        return 84;
    new_instert(ht, key, value, my_strlen(key));
    return 0;
}
