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
