/*
** my_putnbr_base.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/libmy/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 10:02:47 2017 MARZI Nicolas
** Last update Thu Jun  8 10:02:47 2017 MARZI Nicolas
*/

#include <unistd.h>

void    my_putchar(char str);

void    my_putnbr_base(int nbr, char *base)
{
  int    baseNb;
  baseNb = my_strlen(base);

  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  if (nbr >= 1 * baseNb)
    my_putnbr_base(nbr / baseNb, base);
  my_putchar(base[(nbr % baseNb)]);
  nbr = nbr / baseNb;
}
