/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** ls-desu
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

void l_1_case_2(int nb_ele, struct Info *inf, int *lRdrt, DIR *dir)
{
    inf = size_filler(inf, nb_ele);
    inf = nb_filler(inf, nb_ele);
    for (int i = 0; i < nb_ele; i++)
        inf = sort(inf, nb_ele, lRdrt);
    dir_dipslay(nb_ele, inf, lRdrt);
    closedir(dir);
}

void l_1_case(int argc, char *argv[], int *lRdrt, int pos)
{
    DIR *dir;
    struct dirent *dp;
    struct stat sb;
    struct Info *inf;
    int nb_ele = 0;
    int j = 0;

    for (int i = pos; i < argc; i++) {
        if (argv[i][0] != '-') {
            stat(argv[i], &sb);
            if (S_ISDIR(sb.st_mode) == 0)
                return l_1_case(argc, argv, lRdrt, (pos + 1));
            dir = opendir(argv[i]);
            nb_ele = number(argv[i]);
            inf = malloc(nb_ele * sizeof(struct Info));
            for (j = 0; (dp = readdir(dir)) != NULL; inf[j++].na = dp->d_name);
            inf = l_1_filler(argv[i], lRdrt, nb_ele, inf);
            l_1_case_2(nb_ele, (inf - (nb_ele - 1)), lRdrt, dir);
        }
    }
}

int *option_checker(int argc, char *argv[])
{
    int *lRdrt = (int *)malloc(5 * sizeof(int));

    if (lRdrt == NULL)
        return NULL;
    for (int i = 0; i < 5; lRdrt[i++] = 0);
    for (int i = 1; i < argc; i++)
        for (int j = 1; argv[i][j] != '\0'; j++)
            if (argv[i][0] == '-') {
                if (argv[i][j] == 'l')
                    lRdrt[0] = 1;
                if (argv[i][j] == 'R')
                    lRdrt[1] = 1;
                if (argv[i][j] == 'd')
                    lRdrt[2] = 1;
                if (argv[i][j] == 'r')
                    lRdrt[3] = 1;
                if (argv[i][j] == 't')
                    lRdrt[4] = 1;
            }
    return lRdrt;
}

int main(int argc, char *argv[])
{
    int nb_arg = 0;
    int *lRdrt = option_checker(argc, argv);
    char **arg = arg_finder(argc, argv, &nb_arg);

    if (lRdrt == NULL || arg == NULL)
        return 84;
    d_only(nb_arg, arg, lRdrt);
    file(nb_arg, arg, lRdrt);
    l_1_case(nb_arg, arg, lRdrt, 0);
}