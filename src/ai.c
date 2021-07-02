/*
** EPITECH PROJECT, 2021
** B-AIA-200-BDX-2-1-n4s-damien.antoniou
** File description:
** ai
*/

#include <unistd.h>
#include "nfors.h"

void init_ai(info_t *info)
{
    info->speed = 1;
    info->wheels = 0;
    info->checkdir = 0;
    info->checkspeed = 0;
    info->captors[31] = -1;
}

void move(info_t *info, char **cmd)
{
    if (info->checkspeed != info->speed) {
        forward(info->speed);
        ask(cmd);
        info->checkspeed = info->speed;
    }
    if (info->checkdir != info->wheels) {
        set_dir(info->wheels);
        ask(cmd);
        info->checkdir = info->wheels;
    }
}

int ai(void)
{
    info_t info;
    char *cmd;

    init_ai(&info);
    write(1, "START_SIMULATION\n", 17);
    ask(&cmd);
    while (1) {
        if (get_info(&info) == -1)
            break;
        if (info.line > 32)
            get_stats_info(&info);
        move(&info, &cmd);
    }
    write(1, "STOP_SIMULATION\n", 16);
    return (0);
}