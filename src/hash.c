/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** hash.c
*/

#include "../include/hashtable.h"

static char *shiftkey(char *key, int shift_key)
{
    int len_str = my_strlen(key);
    char *result = malloc((len_str + 1) * sizeof(char));

    for (int i = 0; key[i]; i++)
        result[i] = (key[i] + shift_key) % 127;
    result[len_str] = '\0';
    return result;
}

int hash(char *key, int len)
{
    int shift_key = GET_SHIFT_KEY(key, len / 2);
    char *str = shiftkey(key, shift_key);
    int calc = 0;

    for (int i = 0; str[i]; i++)
        calc += str[i];
    for (int i = 0; i < str[0]; i++)
        calc += (calc * 5) / 2;
    if (calc < 0)
        calc *= -1;
    free(str);
    return calc;
}
