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

void ld(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    byte type_param;
    byte nb_register;

    type_param = (*memory)[cursor->position + 1];

    if (!is_type_param_valid(0x02, type_param))
    {
        ++(cursor->position);
        return;
    }

    if (type_param >> 6 == CODED_DIR)
        nb_register = (*memory)[cursor->position + 1 + DIR_SIZE + 1];
    else
        nb_register = (*memory)[cursor->position + 1 + IND_SIZE + 1];
        
    if (nb_register > REG_NUMBER || nb_register < 1)
    {
        ++(cursor->position);
        return;
    }
    if (type_param >> 6 == CODED_DIR)
    {
        cursor->registers[nb_register] = read_byte_to_int(memory, cursor->position + 2, DIR_SIZE);
        cursor->position = (cursor->position + DIR_SIZE + 2 + 1) % MEM_SIZE;
    }
    else 
    {
        cursor->registers[nb_register] = read_byte_to_int(memory, 
        ((read_byte_to_int(memory, cursor->position + 2, IND_SIZE) % IDX_MOD) + cursor->position) % MEM_SIZE, 
        REG_SIZE);
        cursor->position = (cursor->position + IND_SIZE + 2 + 1) % MEM_SIZE;
    }

    if ( cursor->registers[nb_register] == 0)
        cursor->registers[0] = 1;
    else 
        cursor->registers[0] = 0;
    bypass_programs(programs, nb_programs);
}
