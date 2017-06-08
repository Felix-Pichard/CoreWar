/*
** cycle.h for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Tue Jun  6 16:28:53 2017 VIALLON Louis
*/

#include <stdlib.h>
#include "libmy.h"
#include "error.h"
#include "memory.h"
#include "op.h"

unsigned char *init_mem()
{
    byte  *memory;
    int     i;

    if ((memory = (byte *)malloc(sizeof(byte) * MEM_SIZE)) == NULL)
        my_error(5);
    for (i = 0; i < MEM_SIZE; ++i)
        memory[i] = 0;
    return (memory);
}

int dump(byte *memory)
{
    int i;
    
    for (i = 0; i < MEM_SIZE; ++i)
    {
        if (i != 0 && (i % 32 == 0))
            my_putstr("\n");
        my_putnbr_base((int)memory[i], "0123456789ABCDEF");
    }
    return (0);
}
