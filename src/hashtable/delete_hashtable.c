/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** delete_hashtable.c
*/

#include "../../include/hashtable.h"

static void del_ht(hashtable_t *ht)
{
    data_t **data = ht->data;
    data_t *tmp_data;
    h_index_t *current_index;
    h_index_t *tmp_index;

    for (int i = 0; data[i]; i++) {
        tmp_data = data[i];
        current_index = data[i]->index_ht;
        while (current_index) {
            tmp_index = current_index;
            current_index = current_index->next;
            free(tmp_index);
        }
        free(tmp_data);
    }
    free(ht->data);
    free(ht);
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    del_ht(ht);
}
