/*
** my_strncmp.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:23:53 2015 MARZI Nicolas
** Last update Tue Oct  6 10:02:08 2015 MARZI Nicolas
*/

int	my_strlen_cmp(char *str, int n);

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	s1_len;
  int	s2_len;
  i = 0;
  s1_len = my_strlen_cmp(s1, n);
  s2_len = my_strlen_cmp(s2, n);
  if (s1_len == s2_len)
    {
      while ((*s1 || *s2) && i < n)
      {
	if (*s1 > *s2)
	  return (1);
	else if (*s1 < *s2)
	  return (-1);
	s1++;
	s2++;
	i++;
      }
    }
    if (s1_len > s2_len)
      return (1);
    else if (s1_len < s2_len)
      return (-1);
    return (0);
}

int     my_strlen_cmp(char *str, int n)
{
  int 	length;
  length = 0;

  while (str[length] != '\0')
  {
    length++;
  }
  if (length > n)
    return (n);

  return (length);
}
