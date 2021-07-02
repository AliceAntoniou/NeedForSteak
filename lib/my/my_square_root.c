/*
** EPITECH PROJECT, 2020
** my compute square root
** File description:
** return the square root
*/

int my_compute_square_root(int nb)
{
    int res = 2;

    if (nb == 1)
        return (1);
    while (res <= nb / 2) {
        if (nb == res * res)
            return (res);
        res++;
    }
    return (0);
}