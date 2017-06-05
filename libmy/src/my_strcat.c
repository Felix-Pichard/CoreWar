/*
** my_strcat.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:25:03 2015 MARZI Nicolas
** Last update Mon Oct  5 17:47:32 2015 MARZI Nicolas
*/

int    	my_strlen(char *str);

char	*my_strcat(char *str1, char *str2)
{
  int 	i;
  int 	j;
  i = 0;
  j = 0;

  while (str1[i] != '\0')
    i++;
	
  while (str2[j] != '\0')
  {
    str1[i] = str2[j];
    i++;
    j++;
  }

  return (str1);
}
