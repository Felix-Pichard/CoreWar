/*
** my_str_to_wordtab.c for JOUR_07 in /home/marzi_n/Piscine/C/Jour_07/marzi_n/my_str_to_wordtab
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Oct 05 10:46:49 2015 MARZI Nicolas
** Last update Tue Oct  6 13:22:41 2015 MARZI Nicolas
*/

#include "libmy.h"

char  **my_init_tab(char **response, int nb_word, int nb_str);
char  **my_str_to_wordtab_core(char *str, char **response, int i, int j);

char	**my_str_to_wordtab(char *str)
{
  char  **response;
  int	i;
  int	j;
  response = safe_malloc(10);
  i = 0;
  j = 0;

  response = my_str_to_wordtab_core(str, response, i, j);
  return (response);
}

char	**my_str_to_wordtab_core(char *str, char **response, int i, int j)
{
  int 	k;
  int	letter;
  k = 0;
  letter = 1;
  response = my_init_tab(response, my_wordlen(str), my_strlen(str));
  while (i < my_strlen(str))
  {
    if (my_is_alphanum(str[i]))
      {
	response[j][k] = str[i];
	k++;
	letter = 0;
      }
    else if (!my_is_alphanum(str[i]) && letter == 0)
      {
	response[j][k] = '\0';
	k = 0;
	j++;
	letter = 1;
      }
    else
      letter = 1;
    i++;
  }
  return (response);
}

char	**my_init_tab(char **response, int nb_word, int nb_str)
{
  int	i;
  i = 0;
  response = safe_malloc(nb_word * sizeof(char*));
  while (i < nb_word)
  {
    response[i] = safe_malloc(nb_str * sizeof(char));
    i++;
  }
  return (response);
}
