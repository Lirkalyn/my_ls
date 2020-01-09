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

char *l_1_case(int argc, char *argv[], int *lRdrt)
{
    //char *rsl;// = (char *)
    DIR *dir;
    struct dirent *dp;
    struct stat sb;
    struct passwd *pas;
    struct group *gro;

    for (int i = 1; i < argc; i++)
        if (argv[i][0] != '-') {
            dir = opendir(argv[i]);
            /*while ((dp = readdir(dir)) != NULL)
                printf("d_ino = %ld, d_re = %d, d_ty = %c, d_na = %s\n", dp->d_ino, dp->d_reclen, dp->d_type, dp->d_name);
            printf("\nstat\n\n");
            stat("Makefile", &sb);
            printf("st_dev = %ld, st_ino = %ld, st_mode = %d, *st_nlink = %ld, *st_uid = %d, st_*gid = %d, st_rdev = %ld, *st_size = %ld, st_blksize = %ld, *(half)st_blocks = %ld, st_atime = %ld, *st_mtime = %ld, st_ctime = %ld\n", sb.st_dev, sb.st_ino, sb.st_mode, sb.st_nlink, sb.st_uid, sb.st_gid, sb.st_rdev, sb.st_size, sb.st_blksize, sb.st_blocks, sb.st_atime, sb.st_mtime, sb.st_ctime);
            (sb.st_mode & S_IRUSR) ? printf("r\n") : printf("-\n");
            printf("time = %s", ctime(&sb.st_mtime));
            pas = getpwuid(sb.st_uid);
            printf("\ngetpwuid\n\n");
            printf("*pw_name = %s, pw_passwd = %s, pw_uid = %d, pw_gid = %d, pw_gecos = %s, pw_dir = %s, pw_shell = %s\n", pas->pw_name, pas->pw_passwd, pas->pw_uid, pas->pw_gid, pas->pw_gecos, pas->pw_dir, pas->pw_shell);
            gro = getgrgid(sb.st_gid);
            printf("\ngetpwuid\n\n");
            printf("gr_name = %s, gr_passwd = %s, gr_gid = %d\n", gro->gr_name, gro->gr_passwd, gro->gr_gid);*/
        }
}

char *l_0_case(int argc, char *argv[], int *lRdrt)
{}

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
    int *lRdrt = option_checker(argc, argv);
    char *rsl;

    if (argc == 1 || lRdrt == NULL)
        return 0;
    if (lRdrt[0] == 1)
        rsl = l_1_case(argc, argv, lRdrt);
    else if (lRdrt[0] == 0)
        rsl = l_0_case(argc, argv, lRdrt);
//    for (int i = 0; i < 5; i++)
//        printf("%d\n", lRdrt[i]);
}