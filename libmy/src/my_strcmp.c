/*
** my_strcmp.c for MY_STRCMP in /home/marzi_n/Piscine/C/Jour_04/marzi_n/my_strcmp
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 13:46:39 2015 MARZI Nicolas
** Last update Sat Oct  3 14:36:01 2015 MARZI Nicolas
*/

int	my_strlen(char *str);

int	my_strcmp(char *s1, char *s2)
{
  int	s1_len;
  int	s2_len;
  s1_len = my_strlen(s1);
  s2_len = my_strlen(s2);
  if (s1_len == s2_len)
    {
      while (*s1 || *s2)
      {
	if (*s1 > *s2)
	  return (1);
	else if (*s1 < *s2)
	  return (-1);

	s1++;
	s2++;
      }
      return (0);
    }
  else if (s1_len > s2_len)
    return (1);
  else if (s1_len < s2_len)
    return (-1);

  return (0);
}
