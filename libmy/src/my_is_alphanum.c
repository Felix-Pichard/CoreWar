/*
** my_is_alphanum.c for JOUR_07 in /home/marzi_n/Piscine/C/Jour_07/marzi_n/my_str_to_wordtab
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Oct 05 13:20:07 2015 MARZI Nicolas
** Last update Tue Oct  6 09:52:57 2015 MARZI Nicolas
*/

int	my_is_alphanum(char c)
{
  if ((c < '0' || c > '9') &&
      (c < 'A' || c > 'Z') &&
      (c < 'a' || c > 'z'))
    	return (0);

  return (1);
}
