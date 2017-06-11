/*
** my_strlen.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:16:07 2015 MARZI Nicolas
** Last update Tue Oct  6 10:01:30 2015 MARZI Nicolas
*/

#include "game.h"
#include "instructions.h"

void st(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    byte type_param;
    byte nb_register_src;
    byte nb_register_dest;
    int i;

    type_param = (*memory)[cursor->position + 1] % MEM_SIZE;
    if (!is_type_param_valid(0x03, type_param))
    {
        cursor->position = (cursor->position + 1) % MEM_SIZE;
        return;
    }
    nb_register_src = get_param_value(memory, cursor, 1);
    if (nb_register_src > REG_NUMBER || nb_register_src < 1)
    {
        cursor->position = (cursor->position + 1) % MEM_SIZE;
        return;
    }
    nb_register_dest = get_param_value(memory, cursor, 2);
    if (((type_param >> 4) & 0x03) == CODED_IND)
    {
        int value = cursor->registers[nb_register_src];
        for (i = 0; i < 4; i++) 
            (*memory)[(cursor->position + nb_register_dest + i) % MEM_SIZE] = (byte) value >> ((4 - i - 1) * 8);
        cursor->position = (cursor->position + IND_SIZE + T_REG + 2) % MEM_SIZE;
    }
    else 
    {
        cursor->registers[nb_register_dest] = cursor->registers[nb_register_src];
        cursor->position = (cursor->position + T_REG + T_REG + 2) % MEM_SIZE;
    }
    bypass_programs(programs, nb_programs);
}
