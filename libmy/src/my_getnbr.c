/*
** my_getnbr.c for MYLIB  in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Fri Oct  2 15:20:39 2015 MARZI Nicolas
** Last update Wed Oct  7 18:31:20 2015 MARZI Nicolas
*/

int    my_strlen(char *str);
int    my_pow(int a, int b);

int	my_getnbr(char *str)
{
  int 	response;
  int	factor;
  int	nbr;
  int 	length;
  int 	i;
  response = 0;
  factor = 1;
  nbr = 0;
  length = my_strlen(str);
  i = 0;
  while (i < length)
  {
    if (str[i] <= 57 && str[i] >= 48)
      {
	response *= 10;
       	response += str[i] - 48;
	nbr++;
      }
    else if (str[i] == 45 && nbr == 0)
      factor *= -1;
    else if (str[i] != 43)
      i = length;
    i++;
  }
  return (response * factor);
}
