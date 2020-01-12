/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** test-desu
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

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return ((s1[i] - s2[i]));
    return (0);
}

/*int pre_move(char *str1, char *str2, int *len)
{
    for (int i = 0; (i < (len[0] + 1) && i < (len[1] + 1)); i++) {
        if (str1[i] < str2[2])
            return 1;
    }
    return 0;
}

char **arg_finder_2(int nb_arg, char **rsl)
{
    int len[2] = {[0 ... 1] = 0};
    char *tmp;

    for (int i = 0; i < (nb_arg - 1); i++) {
        for (len[0] = 0; rsl[i][len[0]] != '\0'; len[0] += 1);
        for (len[1] = 0; rsl[(i + 1)][len[1]] != '\0'; len[1] += 1);
        for (int j = 0; (j < (len[0] + 1) && j < (len[1] + 1)); j++)
            if (pre_move(rsl[i], rsl[(i + 1)], len)) {
//            if (pre_move(rsl[i], rsl[(i + 1)], j)) {
                tmp = rsl[i];
                rsl[i] = rsl[(i + 1)];
                rsl[(i + 1)] = tmp;
            }
    }
    return rsl;
}*/

char **arg_finder(int argc, char *argv[], int *nb_arg)
{
    struct stat sb;
    int pos = 0;
    char **rsl;

    for (int i = 1; i < argc; i++)
        if (argv[i][0] != '-')
            if (stat(argv[i], &sb) == 0)
                *nb_arg += 1;
    rsl = (char **)malloc((*nb_arg + 1) * sizeof(char *));
    if (rsl == NULL)
        return NULL;
    for (int i = 1; i < argc; i++)
        if (argv[i][0] != '-')
            if (stat(argv[i], &sb) == 0) {
                rsl[pos++] = argv[i];
            }
    if (*nb_arg == 0) {
        rsl[0] = ".\0";
        *nb_arg += 1;
    }
//    for (int i = 0; i < *nb_arg; i++)
//        rsl = arg_finder_2(*nb_arg, rsl);
    return rsl;
}

struct Info *sort(struct Info *inf, int nb, int *lRdrt)
{
    int len[2] = {[0 ... 1] = 0};
//    int len1 = 0;
//    int len2 = 0;
    struct Info tmp;
/*
//    printf("\n");
    for (int i = 0; i < (nb - 1); i++) {
        for (len[0] = 0; inf[i].na[len[0]] != '\0'; len[0] += 1);
        for (len[1] = 0; inf[(i + 1)].na[len[1]] != '\0'; len[1] += 1);
        for (int j = 0; (j < (len[0] + 1) && j < (len[1] + 1)); j++)
//            if (inf[i].na[j] > inf[(i + 1)].na[j]) {
            if (pre_move(inf[i].na, inf[(i + 1)].na, len)) {
//            if (pre_move(inf[i].na, inf[(i + 1)].na, j)) {
//                printf("ok\n");
                tmp = inf[i];
                inf[i] = inf[(i + 1)];
                inf[(i + 1)] = tmp;
            }
    }*/
    for (int i = 0; (i < (nb - 1) && lRdrt[4] == 1); i++)
        if (inf[i].time < inf[(i + 1)].time) {
            tmp = inf[i];
            inf[i] = inf[(i + 1)];
            inf[(i + 1)] = tmp;
        }
//    for (int i = 0; i < nb; i++)
//        printf("%s\n", inf[i].na);
    return inf;
}