/*
** my_wordlen.c for JOUR_07 in /home/marzi_n/Piscine/C/Jour_07/marzi_n/my_str_to_wordtab
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Oct 05 10:48:29 2015 MARZI Nicolas
** Last update Wed Oct  7 18:38:39 2015 MARZI Nicolas
*/

int	my_is_alphanum(char c);

int	my_wordlen(char *str)
{
  int 	length;
  int	i;
  int	letter;
  length = 0;
  i = 0;
  letter = 0;
  if (my_is_alphanum(str[i]))
    length++;
  while (str[i] != '\0')
  {
    if (!my_is_alphanum(str[i]) && letter == 0)
      {		
	length++;
	letter++;
      }
    else if (my_is_alphanum(str[i]))
      letter = 0;
    i++;
  }
  return (length);
}
