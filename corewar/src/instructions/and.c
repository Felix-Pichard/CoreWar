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

void i_and(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    int op_1;
    int op_2;
    int res_reg;
    int res;
    int size_param;

    size_param = (*memory)[(cursor->position + 1) % MEM_SIZE];
    if (!is_type_param_valid(6, size_param))
    {
        cursor->position = (cursor->position + 1) % MEM_SIZE;
        return;
    }
    op_1 = get_param_value_process(memory, cursor, 1);
    op_2 = get_param_value_process(memory, cursor, 2);
    res_reg = get_param_value(memory, cursor, 3);
    if (res_reg > 0 && res_reg <= REG_NUMBER)
    {
        res = op_1 & op_2;
        cursor->registers[res_reg] = res;
        cursor->registers[0] = (res == 0) ? 1 : 0;
        cursor->position = (cursor->position + 2 + get_size_param(size_param, 1) + get_size_param(size_param, 2) + get_size_param(size_param, 3)) % MEM_SIZE;
    }
    else
        cursor->position = (cursor->position + 1) % MEM_SIZE;
    bypass_programs(programs, nb_programs);
}
