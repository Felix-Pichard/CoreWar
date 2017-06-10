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
    nb_register = get_param_value(memory, cursor, 2);        
    if (nb_register > REG_NUMBER || nb_register < 1)
    {
        ++(cursor->position);
        return;
    }
    cursor->registers[nb_register] = get_param_value_process(memory, cursor, 1);
    cursor->position = (cursor->position + get_size_param(type_param, 1) + 2 + 1) % MEM_SIZE;
    if ( cursor->registers[nb_register] == 0)
        cursor->registers[0] = 1;
    else 
        cursor->registers[0] = 0;
    bypass_programs(programs, nb_programs);
}
