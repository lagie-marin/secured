/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** hashtable.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #define GET_SHIFT_KEY(keys, center) ((keys[center]) * (center))
    #define GET_INDEX(_hash, len, index_max) ((_hash) % (index_max))
    #define RETURN(cond, output) if(cond) return output
typedef struct hashtable_s hashtable_t;
typedef struct h_index_s h_index_t;
typedef struct data_s data_t;
typedef unsigned int ui;

struct h_index_s {
    int key;
    char *data;
    int index;
    h_index_t *next;
    h_index_t *prev;
};

struct data_s {
    ui index;
    h_index_t *index_ht;
};

struct hashtable_s {
    data_t **data;
    int (*hash)(char *, int);
    int max_index;
};
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
int hash(char *key, int len);
int my_strlen(char const *str);
int my_intlen(int value);
int power(int nb, int p);
void my_itoa(int value, char *buffer);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_put_nbr(int n);
int ht_insert(hashtable_t *ht, char *key, char *value);
void ht_dump(hashtable_t *ht);
char *ht_search(hashtable_t *ht, char *key);
int ht_delete(hashtable_t *ht, char *key);
#endif
