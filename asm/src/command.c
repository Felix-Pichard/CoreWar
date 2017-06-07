/*
** command.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 11:03:02 2017 MARZI Nicolas
** Last update Wed Jun  7 11:03:02 2017 MARZI Nicolas
*/

#include "libmy.h"
#include "command.h"

void print_header(header_t *header)
{
    my_putstr("Header :\n");
    my_putstr("\tMagic   : ");my_put_nbr(header->magic);my_putstr("\n");
    my_putstr("\tName    : ");my_putstr(header->prog_name);my_putstr("\n");
    my_putstr("\tComment : ");my_putstr(header->comment);my_putstr("\n");
    my_putstr("\tSize    : ");my_put_nbr(header->prog_size);my_putstr("\n");
}