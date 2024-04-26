/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** ht_dump.c
*/

#include "../../include/hashtable.h"

static void dump(hashtable_t *ht)
{
    data_t **data = ht->data;
    h_index_t *current_index;

    for (int i = 0; data[i]; i++) {
        write(1, "[", 1);
        my_put_nbr(i);
        write(1, "]:\n", 3);
        current_index = data[i]->index_ht;
        while (current_index) {
            write(1, "> ", 2);
            my_put_nbr(current_index->key);
            write(1, " - ", 3);
            write(1, current_index->data, my_strlen(current_index->data));
            write(1, "\n", 1);
            current_index = current_index->next;
        }
    }
}

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    dump(ht);
}
