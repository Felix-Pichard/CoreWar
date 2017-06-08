/*
** cycle.h for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Thu Jun  8 18:14:15 2017 MARZI Nicolas
*/

#include <stdlib.h>
#include "libmy.h"
#include "error.h"
#include "memory.h"
#include "op.h"

void init_mem(byte **memory)
{
    int     i;

    for (i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
}

int dump(byte memory[])
{
    int i;
    
    for (i = 0; i < MEM_SIZE; i++)
    {
        if (i != 0 && (i % 32 == 0))
            my_putstr("\n");
        put_hex(memory[i]);
    }
    return (0);
}


int dump_n(byte memory[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        if (i != 0 && (i % 32 == 0))
            my_putstr("\n");
        put_hex(memory[i]);
    }
    return (0);
}
