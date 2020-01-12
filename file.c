/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** file-desu
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

int file_number(int argc, char *argv[])
{
    struct stat sb;
    int file_nb = 0;

    for (int i = 0; i < argc; i++) {
        stat(argv[i], &sb);
        if (S_ISREG(sb.st_mode))
            file_nb += 1;
    }
    return file_nb;
}

int file(int argc, char *argv[], int *lRdrt)
{
    struct stat sb;
    int file_nb = file_number(argc, argv);
    struct Info *inf = malloc(file_nb * sizeof(struct Info));
    int j = 0;

    for (int i = 0; i < argc; i++) {
        stat(argv[i], &sb);
        if (S_ISREG(sb.st_mode))
            inf[j++].na = argv[i];
    }
    for (int i = 0; i < file_nb; i++, inf += 1) {
        stat(inf->na, &sb);
        inf = struc_filler(sb, inf);
    }
    inf -= (file_nb);
    inf = size_filler(inf, file_nb);
    for (int i = 0; i < file_nb; i++)
        inf = sort(inf, file_nb, lRdrt);
    file_dipslay(file_nb, inf, lRdrt);
//    for (int i = 0; i < file_nb; i++)
//        printf("type_rights = %s, nb = %d, user = %s, group = %s, tot = %d, size = %llu, size_d = |%s|,date = %s, time = %llu, name = %s, uid = %d, gid = %d\n", inf[i].type_rights, inf[i].nb, inf[i].user, inf[i].group, inf[i].tot, inf[i].size, inf[i].size_d, inf[i].date, inf[i].time, inf[i].na, inf[i].uid, inf[i].gid);
}

void d_only(int argc, char *argv[], int *lRdrt)
{
    if (lRdrt[0] == 0 && lRdrt[1] == 0 && lRdrt[2] == 1 && lRdrt[3] == 0) {
        for (int i = 0; i < argc; i++) {
            my_putstr(argv[i], 0);
        }
    }
    else if (lRdrt[0] == 0 && lRdrt[1] == 0 && lRdrt[2] == 1 && lRdrt[3] == 1) {
        for (int i = (argc - 1); i >= 0; i--) {
            my_putstr(argv[i], 0);
        }
    }
}