/*
** my_pow.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:08:36 2015 MARZI Nicolas
** Last update Tue Oct  6 09:54:15 2015 MARZI Nicolas
*/

int     my_pow(int a, int b)
{
  int	i;
  int   response;
  response = 1;
  i = 0;

  if (b <= 0)
    return (1);

  while (i < b)
    {
      response *= a;
      i++;
    }

  return (response);
}
