/*
** libmy.h for BATTLE_FOR_MIDWUT in /home/marzi_n/Piscine/C/BattleForMidwut/marzi_n/Introduction
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  8 18:35:51 2015 MARZI Nicolas
** Last update Thu Oct  8 20:25:41 2015 MARZI Nicolas
*/

#ifndef __LIBMY_H__
#define __LIBMY_H__

int	    my_getnbr(char *str);
int     my_is_alphanum(char c);
int     my_isneg(int n);
int     my_nb_len(int n);
int     my_pow(int a, int b);
void    my_putchar(char c);
void    my_put_nbr(int n);
void    my_putstr(char *str);
char    *my_strcat(char *str1, char *str2);
int     my_strcmp(char *s1, char *s2);
char    *my_strcpy(char *dest, char *src);
char    *my_strncat(char *str1, char *str2, int n);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strncpy(char *dest, char *src, int n);
char    *my_strdup(char *str);
int   	my_strlen(char *str);
char    *my_strstr(char *str, char *to_find);
char    **my_str_to_wordtab(char *str);
void    my_swap(int *a, int *b);
int     my_wordlen(char *str);
void    my_putnbr_base(int nbr, char *base);
int     my_strspn (const char *s, const char *accept);

#endif
