/*
** EPITECH PROJECT, 2021
** B-AIA-200-BDX-2-1-n4s-damien.antoniou
** File description:
** get_info
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nfors.h"

int ask(char **cmd)
{
    size_t str_size = 0;

    if (getline(cmd, &str_size, stdin) == -1) {
        return (1);
    }
    return (0);
}

int finish(char *str)
{
    if (str != NULL) {
        if (strcmp("Lap Cleared", str) == 0 ||
        strcmp("Track Cleared", str) == 0)
            return (1);
    }
    return (0);
}

int get_info(info_t *info)
{
    char *str = NULL;
    char **parsed;
    int cpy = 0;

    write(1, "GET_INFO_LIDAR\n", 15);
    if (ask(&str) == 1)
        return 0;
    take_word(str, &parsed, &cpy);
    info->line = cpy;
    if (info->line > 32) {
        for (int pos = 0; pos < 32; pos++)
            info->captors[pos] = atof(parsed[3 + pos]);
        if (finish(parsed[35]) == 1)
            return (-1);
        return (1);
    }
    return 1;
}