/*
** my_putchar.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 18:54:48 2015 MARZI Nicolas
** Last update Tue Oct  6 09:54:32 2015 MARZI Nicolas
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
