/*
** my_putstr.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:15:08 2015 MARZI Nicolas
** Last update Tue Oct  6 09:59:36 2015 MARZI Nicolas
*/

#include <unistd.h>

int	my_strlen(char *str);

void    my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
