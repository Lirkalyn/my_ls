/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** more-desu
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

int strcm(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (1);
    return (0);
}

int my_put_nbr_3(int nb)
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
    return 0;
}

int my_put_nbr_2(int nb)
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
    my_putchar('\n');
    return 0;
}

void dir_dipslay_2(int nb_ele, struct Info *inf, int *lRdrt)
{
    if (lRdrt[3] == 0)
        for (int i = 0; i < nb_ele; i++)
            if (strcm(inf[i].na , ".") && strcm(inf[i].na , "..")
                && (inf[i].type_rights[0] != 'l') && (inf[i].na[0] != '.')) {
                my_putstr(inf[i].type_rights, 1);
                my_putstr(inf[i].nb_d, 1);
                my_putstr(inf[i].user, 1);
                my_putstr(inf[i].group, 1);
                my_putstr(inf[i].size_d, 1);
                my_putstr(inf[i].date, 1);
                my_putstr(inf[i].na, 0);
            }
    else if (lRdrt[3] == 1)
        for (int i = (nb_ele - 1); i >= 0; i--)
            if (strcm(inf[i].na , ".") && strcm(inf[i].na , "..")
                && (inf[i].type_rights[0] != 'l') && (inf[i].na[0] != '.')) {
                my_putstr(inf[i].type_rights, 1);
                my_put_nbr(inf[i].nb);
                my_putstr(inf[i].user, 1);
                my_putstr(inf[i].group, 1);
                my_putstr(inf[i].size_d, 1);
                my_putstr(inf[i].date, 1);
                my_putstr(inf[i].na, 0);
            }
}

void dir_dipslay(int nb_ele, struct Info *inf, int *lRdrt)
{
    int total = 0;

    if (lRdrt[0] == 0) {
        if (lRdrt[3] == 0)
            for (int i = 0; i < nb_ele; i++)
                if (strcm(inf[i].na , ".") && strcm(inf[i].na , "..")
                    && (inf[i].type_rights[0] != 'l') && (inf[i].na[0] != '.'))
                    my_putstr(inf[i].na, 0);
        else if (lRdrt[3] == 1)
            for (int i = (nb_ele - 1); i >= 0; i--)
                if (strcm(inf[i].na , ".") && strcm(inf[i].na , "..")
                    && (inf[i].type_rights[0] != 'l') && (inf[i].na[0] != '.'))
                    my_putstr(inf[i].na, 0);
    }
    else if (lRdrt[0] == 1) {
        for (int i = 0; i < nb_ele; i++)
            if (strcm(inf[i].na , ".") && strcm(inf[i].na , "..")
                && (inf[i].type_rights[0] != 'l') && (inf[i].na[0] != '.'))
                total += inf[i].tot;
        my_putstr("total", 1);
        my_put_nbr_2(total);
        dir_dipslay_2(nb_ele, inf, lRdrt);
    }
}