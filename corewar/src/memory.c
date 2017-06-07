/*
** cycle.h for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Tue Jun  6 16:28:53 2017 VIALLON Louis
*/

#include <libzvbi.h>
#include <malloc.h>
#include <stdlib.h>
#include "libmy.h"
#include "../includes/memory.h"
#include "../includes/op.h"

unsigned char *init_mem()
{
    t_byte  *memory;
    int     i;

    if ((memory = (t_byte *)malloc(sizeof(t_byte) * MEM_SIZE)) == NULL)
    {
        my_putstr("Tg Felix\n");
        exit(-1);
    }
    for (i = 0; i < MEM_SIZE; ++i)
        memory[i] = 0;
    return (memory);
}