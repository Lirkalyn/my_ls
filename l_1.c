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

#include <stdio.h>

struct Info *size_filler(struct Info *inf, int nb_ele)
{
    int max = 0;
    int tmp_max = 0;
    unsigned long long tmp_size;

    for (int i = 0; i < nb_ele; i++) {
        tmp_size = inf[i].size;
        for (tmp_max = 0; tmp_size != 0; tmp_max += 1)
            tmp_size /= 10;
        max = (tmp_max > max) ? tmp_max : max;
    }
    if (max == 0)
        max = 1;
    for (int i = 0; i < nb_ele; i++) {
        tmp_size = inf[i].size;
        inf[i].size_d = put_nb(max, tmp_size);
    }
    return inf;
}

struct Info *right_filler(struct stat sb, struct Info *inf)
{
    inf->type_rights[0] = (S_ISDIR(sb.st_mode)) ? 'd' : '-';
    inf->type_rights[0] = (S_ISLNK(sb.st_mode)) ? 'l' : '-';
    inf->type_rights[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
    inf->type_rights[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
    inf->type_rights[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
    inf->type_rights[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
    inf->type_rights[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
    inf->type_rights[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
    inf->type_rights[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
    inf->type_rights[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
    inf->type_rights[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
    inf->type_rights[10] = '\0';
    return inf;
}

struct Info *struc_filler(struct stat sb, struct Info *inf)
{
    char *time;
    struct passwd *pas;
    struct group *gro;

    pas = getpwuid(sb.st_uid);
    gro = getgrgid(sb.st_gid);
    time = ctime(&sb.st_mtime);
    inf->nb = sb.st_nlink;
    inf->user = pas->pw_name;
    inf->group = gro->gr_name;
    inf->tot = (sb.st_blocks / 2);
    inf->size = sb.st_size;
    for (int i = 4; i < 16; i++)
        inf->date[(i - 4)] = time[i];
    inf->date[12] = '\0';
    inf->time = sb.st_mtime;
    inf->uid = sb.st_uid;
    inf->gid = sb.st_gid;
    inf = right_filler(sb, inf);
    return inf;
}

char *path_giver(char *path, struct Info *inf, int *len)
{
    char *rsl;
    int i_j[2] = {[0 ... 1] = 0};

    if (path[len[0] - 1] == '/') {
        rsl = (char *)malloc((len[0] + len[1] + 1) * sizeof(char));
        rsl[(len[0] + len[1])] = '\0';
        for (;path[i_j[0]] != '\0'; rsl[i_j[0]] = path[i_j[0]], i_j[0] += 1);
        for (; inf->na[i_j[1]] != '\0'; i_j[1] += 1)
            rsl[(i_j[0] + i_j[1])] = inf->na[i_j[1]];
    }
    else {
        rsl = (char *)malloc((len[0] + len[1] + 2) * sizeof(char));
        rsl[(len[0] + len[1] + 1)] = '\0';
        for (;path[i_j[0]] != '\0'; rsl[i_j[0]] = path[i_j[0]], i_j[0] += 1);
        rsl[i_j[0]] = '/';
        i_j[0] += 1;
        for (; inf->na[i_j[1]] != '\0'; i_j[1] += 1)
            rsl[(i_j[0] + i_j[1])] = inf->na[i_j[1]];
    }
    return rsl;
}

struct Info *l_1_filler(char *path, int *lRdrt, int nb_ele, struct Info *inf)
{
    struct stat sb;
    char *com_path;
    int len[2] = {[0 ... 1] = 0};
    int i_j[2] = {[0 ... 1] = 0};

    for (; path[len[0]] != '\0'; len[0] += 1);
    for (; inf->na[len[1]] != '\0'; len[1] += 1);
    com_path = path_giver(path, inf, len);
    stat(com_path, &sb);
    inf = struc_filler(sb, inf);
    inf = sys_link(com_path, inf);
    nb_ele -= 1;
    if (nb_ele == 0)
        return inf;
    else
        l_1_filler(path, lRdrt, nb_ele, (inf + 1));
}