/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** new_hashtable.c
*/

#include "../../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *begin;
    data_t *new_data;

    if (!hash || len <= 0)
        return NULL;
    begin = malloc(sizeof(hashtable_t));
    begin->max_index = len;
    begin->hash = hash;
    begin->data = malloc((len + 1) * sizeof(data_t));
    for (int i = 0; i < len; i++) {
        new_data = malloc(sizeof(data_t));
        new_data->index = i;
        new_data->index_ht = NULL;
        begin->data[i] = new_data;
    begin->data[len] = NULL;
    }
    return begin;
}
