/*
** put_hex.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/libmy/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 15:19:49 2017 MARZI Nicolas
** Last update Thu Jun  8 13:15:36 2017 MARZI Nicolas
*/

#include <unistd.h>
#include "../../includes/libmy.h"

void	put_hex_core(unsigned char nbr)
{
  int	baseNb;
  char *base;

  baseNb = 16;
  base = "0123456789abcdef";
  if (nbr >= 1 * baseNb)
    put_hex_core(nbr / baseNb);
  my_putchar(base[(nbr % baseNb)]);
  nbr = nbr / baseNb;
}

void put_hex(unsigned char nbr)
{
    write(1, "0x", 2);
    if (nbr < 16)
        write(1, "0", 1);
    put_hex_core(nbr);
    write(1, " ", 1);
}

