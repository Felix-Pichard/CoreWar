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

void mod(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    int op_1;
    int op_2;
    int res_reg;
    int res;

    if (!is_type_param_valid(0x0f, (*memory)[(cursor->position + 1) % MEM_SIZE]))
    {
        cursor->position = (cursor->position + 1) % MEM_SIZE;
        return;
    }
    op_1 = get_param_value(memory, cursor, 1);
    op_2 = get_param_value(memory, cursor, 2);
    res_reg = get_param_value(memory, cursor, 3);
    if (!(op_1 <= REG_NUMBER && op_1 >= 1 && op_2 <= REG_NUMBER && op_2 >= 1 
        && res_reg <= REG_NUMBER && res_reg >= 1))
    {
        cursor->position = (cursor->position + 1) % MEM_SIZE;
        return;
    }
    res = cursor->registers[op_1] % cursor->registers[op_2];
    cursor->registers[res_reg] = res;
    cursor->registers[0] = (res == 0) ? 1 : 0;
    cursor->position = (cursor->position + T_REG * 3 + 2) % MEM_SIZE;
    bypass_programs(programs, nb_programs);
}
