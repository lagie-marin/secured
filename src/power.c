/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-gauthier.candelier
** File description:
** power.c
*/

#include "../include/hashtable.h"

int power(int nb, int p)
{
    int result = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    for (int i = p - 1; i > 0; i--)
        result *= nb;
    return result;
}
