/*
** my_strstr.c for MY_STRSTR in /home/marzi_n/Piscine/C/Jour_04/marzi_n/my_strstr
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 17:14:06 2015 MARZI Nicolas
** Last update Fri Oct  2 18:32:32 2015 MARZI Nicolas
*/

int	my_strlen(char *str);

char	*my_strstr(char *str, char *to_find)
{
  int	step;
  int	i;
  int	length;
  step = 0;
  i = 0;
  length = my_strlen(to_find);

  while (*str != '\0')
  {
    if (*str == to_find[0])
      {
	while (*(str + i) == to_find[i])
	{
	  step++;
	  if (step == length)
	    return (str);
	  i++;
	}
	i = 0;
      }
    str++;
  }
  return ("null");
}
