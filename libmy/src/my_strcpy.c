/*
** my_strcpy.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:19:25 2015 MARZI Nicolas
** Last update Wed Oct  7 18:38:26 2015 MARZI Nicolas
*/

char	*my_strcpy(char *dest, char *src)
{
  int 	i;
  i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';

  return (dest);
}
