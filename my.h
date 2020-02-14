/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** h-desu
*/

#ifndef _MY_H_
#define _MY_H_

struct Info {
    char type_rights[11];
    int nb;
    char *nb_d;
    char *user;
    char *group;
    int tot;
    unsigned long long size;
    char *size_d;
    char date[13];
    unsigned long long time;
    char *na;
    int uid;
    int gid;
    char *link;
};

struct Info *l_1_filler(char *path, int *lrdrt, int nb_ele, struct Info *inf);
struct Info *right_filler(struct stat sb, struct Info *inf);
struct Info *struc_filler(struct stat sb, struct Info *inf);
struct Info *size_filler(struct Info *inf, int nb_ele);
struct Info *nb_filler(struct Info *inf, int nb_ele);
struct Info *sys_link(char *com_path, struct Info *inf);
char *put_nb(int max, int nb);
int number(char *str);
int file(int argc, char *argv[], int *lrdrt);
struct Info *sort(struct Info *inf, int nb, int *lrdrt);
char **arg_finder(int argc, char *argv[], int *nb_arg);
void my_putchar(char c);
int my_putstr(char *str, int opt);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int *n);
void d_only(int argc, char *argv[], int *lrdrt);
void file_dipslay(int file_nb, struct Info *inf, int *lrdrt);
void dir_dipslay(int file_nb, struct Info *inf, int *lrdrt);
int my_put_nbr_3(int nb);

#endif
