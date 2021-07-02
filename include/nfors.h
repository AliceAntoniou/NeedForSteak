/*
** EPITECH PROJECT, 2021
** nfors
** File description:
** prot.h
*/

#ifndef NFORS
#define NFORS

#include "struct.h"

void forward(double speed);
void set_dir(double angle);
int take_word(char *str, char ***word_list, int *line);
int get_info(info_t *info);
int ask(char **cmd);
int ai(void);
void get_stats_info(info_t *info);

#endif
