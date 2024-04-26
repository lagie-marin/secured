/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** my_strlen.c
*/

#include "../include/hashtable.h"

int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str[i]; i++)
        len++;
    return len;
}
