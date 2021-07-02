/*
** EPITECH PROJECT, 2021
** B-AIA-200-BDX-2-1-n4s-damien.antoniou
** File description:
** stat info
*/

#include "nfors.h"

static void far_check(info_t *info)
{
    if (info->captors[0] < info->captors[30] && info->captors[15] < 700) {
        info->wheels = -0.2;
        info->speed = 0.5;
    }
    if (info->captors[0] > info->captors[30] && info->captors[15] < 700) {
        info->wheels = 0.2;
        info->speed = 0.5;
    }
}

static void mid_check(info_t *info)
{
    if (info->captors[0] < info->captors[30] && info->captors[15] < 500) {
        info->wheels = -0.4;
        info->speed = 0.3;
    }
    if (info->captors[0] > info->captors[30] && info->captors[15] < 500) {
        info->wheels = 0.4;
        info->speed = 0.3;
    }
}

static void close_check(info_t *info)
{
    if (info->captors[0] < 150) {
        info->wheels = -0.5;
        info->speed = 0.1;
    }
    if (info->captors[30] < 150) {
        info->wheels = 0.5;
        info->speed = 0.1;
    }
}

void get_stats_info(info_t *info)
{
    info->wheels = 0;
    if (info->captors[14] < 1200)
        info->speed = 0.3;
    else if (info->captors[14] < 2000)
        info->speed = 0.6;
    else
        info->speed = 0.8;
    far_check(info);
    mid_check(info);
    close_check(info);
}