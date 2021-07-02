/*
** EPITECH PROJECT, 2021
** get_word
** File description:
** get_word function
*/

#include <stdlib.h>
#include "my_lib.h"

int skip(char *str, int loc)
{
    while (str[loc] == ':' && str[loc] != '\0')
        loc++;
    return (loc);
}

int get_word_size(char *str, int loc)
{
    int count = 0;

    while (str[loc] != '\0' && str[loc] != ':') {
        count++;
        loc++;
    }
    return (count);
}

int count_word(char *str)
{
    int index = skip(str, 0);
    int count = 1;

    while (str[index] != '\0') {
        if (str[index] == ':' && str[index + 1] != '\0')
            count++;
        index++;
    }
    return (count);
}

int conclude(char ***word_list, int index)
{
    (*word_list)[index + 1] = NULL;
    return (0);
}

int take_word(char *str, char ***word_list, int *line)
{
    int nb_word = count_word(str);
    int pos = 0;
    int loc = skip(str, 0);
    (*line) = nb_word;
    (*word_list) = malloc(sizeof(char *) * (nb_word + 1));
    for (int index = 0; index < nb_word; index++) {
        (*word_list)[index] = NULL;
        (*word_list)[index] = malloc(sizeof(char) *
        (get_word_size(str, loc) + 1));
        if ((*word_list)[index] == NULL)
            return (84);
        for (; str[loc] != '\0' && str[loc] != ':'; loc++) {
            (*word_list)[index][pos] = str[loc];
            pos++;
        }
        (*word_list)[index][pos] = '\0';
        loc = skip(str, loc);
        pos = conclude(word_list, index);
    }
    return (0);
}
