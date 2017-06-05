/*
** my_strncpy.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:20:04 2015 MARZI Nicolas
** Last update Wed Oct  7 18:31:39 2015 MARZI Nicolas
*/

int	my_nb_len(char *str);

char	*my_strncpy(char *dest, char *src, int n)
{
  int 	i;
  i = 0;

  while (src[i] != '\0')
  {
    if (i < n)
      dest[i] = src[i];
    i++;
  }
  return (dest);
}
