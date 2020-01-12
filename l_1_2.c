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

char *put_nb(int max, int nb)
{
    char *tmp = (char *)malloc((max + 1) * sizeof(char));

    tmp[max] = '\0';
    for (int i = (max - 1); i >= 0; i--)
        if (nb != 0) {
            tmp[i] = ((nb % 10) + '0');
            nb /= 10;
        }
        else if (nb == 0 && i == (max - 1))
            tmp[i] = '0';
        else
            tmp[i] = ' ';
    return tmp;
}

int number(char *str)
{
    DIR *dir;
    struct dirent *dp;
    int rsl = 0;

    dir = opendir(str);
    while ((dp = readdir(dir)) != NULL)
        rsl++;
    closedir(dir);
    return rsl;
}

struct Info *sys_link(char *com_path, struct Info *inf)
{
    struct stat sb;

    lstat(com_path, &sb);
    if (S_ISLNK(sb.st_mode)) {
        inf->size = sb.st_size;
        right_filler(sb, inf);
        inf->link = (char *)malloc((sb.st_size + 1) * sizeof(char));
        readlink(com_path, inf->link, (sb.st_size + 1));
    }
    return inf;
}