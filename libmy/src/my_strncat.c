/*
** my_strncat.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:28:47 2015 MARZI Nicolas
** Last update Mon Oct  5 18:34:46 2015 MARZI Nicolas
*/
char	*my_strncat(char *str1, char *str2, int n)
{
  int 	i;
  int 	j;
  i = 0;
  j = 0;
  while (str1[i] != '\0')
    i++;

  while (j < n)
  {
    str1[i] = str2[j];
    i++;
    j++;
  }
  str1[i] = '\0';
  return (str1);
}
