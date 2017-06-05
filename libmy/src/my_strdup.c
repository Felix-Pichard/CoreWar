/*
** my_strdup.c for JOUR_07 in /home/marzi_n/Piscine/C/Jour_07/marzi_n/my_strdup
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Oct 05 10:14:59 2015 MARZI Nicolas
** Last update Mon Oct  5 17:49:57 2015 MARZI Nicolas
*/

#include <stdlib.h>

int 	my_strlen(char *str);
char 	*my_strcpy(char *dest, char *src);

char 	*my_strdup(char *str)
{
  char 	*dest;
  dest = malloc(sizeof(char) * my_strlen(str));
  dest = my_strcpy(dest, str);

  return (dest);
}
