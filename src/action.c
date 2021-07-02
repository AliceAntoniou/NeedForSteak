/*
** EPITECH PROJECT, 2021
** B-AIA-200-BDX-2-1-n4s-damien.antoniou
** File description:
** action
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void forward(double speed)
{
    char str[331];

    if (speed < 0) {
        speed *= -1;
        sprintf(str, "CAR_BACKWARDS:%.1f\n", speed);
    }else
        sprintf(str, "CAR_FORWARD:%.1f\n", speed);
    write(1, str, strlen(str));
}

void set_dir(double angle)
{
    char str[331];

    sprintf(str, "WHEELS_DIR:%.1f\n", angle);
    write(1, str, strlen(str));
}