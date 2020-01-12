/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** display-desu
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"

#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str, int opt)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    if (opt == 0)
        my_putchar('\n');
    else if (opt == 1)
        my_putchar(' ');
    return (0);
}

int my_put_nbr(int nb)
{
    int a;
    int b;
    _Bool over = 0;

    if (nb >= 10) {
        my_put_nbr_3 (nb / 10);
        a = (nb % 10 + '0');
        if (over == 1 && a == '7') {
            a++;
            over = 0;
        }
        my_putchar(a);
    } else {
        b = (nb + 48);
        my_putchar(b);
    }
    my_putchar(' ');
    return 0;
}

void file_dipslay_2(int file_nb, struct Info *inf, int *lRdrt)
{
    if (lRdrt[3] == 0)
        for (int i = 0; i < file_nb; i++) {
            my_putstr(inf[i].type_rights, 1);
            my_put_nbr(inf[i].nb);
            my_putstr(inf[i].user, 1);
            my_putstr(inf[i].group, 1);
            my_putstr(inf[i].size_d, 1);
            my_putstr(inf[i].date, 1);
            my_putstr(inf[i].na, 0);
        }
    else if (lRdrt[3] == 1)
        for (int i = (file_nb - 1); i >= 0; i--) {
            my_putstr(inf[i].type_rights, 1);
            my_put_nbr(inf[i].nb);
            my_putstr(inf[i].user, 1);
            my_putstr(inf[i].group, 1);
            my_putstr(inf[i].size_d, 1);
            my_putstr(inf[i].date, 1);
            my_putstr(inf[i].na, 0);
        }
}

void file_dipslay(int file_nb, struct Info *inf, int *lRdrt)
{
    if (lRdrt[0] == 0) {
        if (lRdrt[3] == 0)
            for (int i = 0; i < file_nb; i++)
                my_putstr(inf[i].na, 0);
        else if (lRdrt[3] == 1)
            for (int i = (file_nb - 1); i >= 0; i--)
                my_putstr(inf[i].na, 0);
    }
    else if (lRdrt[0] == 1)
        file_dipslay_2(file_nb, inf, lRdrt);
}