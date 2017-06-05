/*
** my_put_nbr.c for MY_PUT_NBR in /home/marzi_n/Piscine/C/Jour_05/marzi_n/my_put_nbr
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Fri Oct  2 14:52:04 2015 MARZI Nicolas
** Last update Wed Oct  7 18:36:36 2015 MARZI Nicolas
*/

#include <unistd.h>

int     my_nb_len(int n);
void	my_putchar(char c);
void	my_putstr(char *str);
void    my_put_nbr_core(int n, int length);
void    my_verif_while_nbr(int n, int boolean, int length);

void	my_put_nbr(int n)
{
  my_put_nbr_core(n, my_nb_len(n));
}

void	my_put_nbr_core(int n, int length)
{
  int	boolean;
  boolean = 1;
  length = my_nb_len(n);
  if (n == -2147483648)
    {
      my_putstr("-2147483648");
      boolean = 0;
    }
  else if (n == 0)
    {
      my_putstr("0");
      boolean = 0;
    }
  else if (n < 0 && boolean)
    {
      my_putchar('-');
      n *= -1;
      length--;
    }
  my_verif_while_nbr(n, boolean, length);
}
void	my_verif_while_nbr(int n, int boolean, int length)
{
  int 	i;
  int	s;
  int 	c;
  i = 0;
  while (length > 0 && boolean)
  {
    s = n;
    while (i < length && boolean)
    {
      c = s % 10;
      s /= 10;
      i++;
    }
    my_putchar(c + '0');
    i = 0;
    length--;
  }
}
