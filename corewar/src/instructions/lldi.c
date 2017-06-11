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

void lldi(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    int res_register;
    int op_1;
    int op_2;
    int dcl_size;
    byte type_param;

    type_param = (*memory)[cursor->position + 1] % MEM_SIZE;
    if (!is_type_param_valid(0x0d, type_param))
    {
        cursor->position = (cursor->position + 1) % MEM_SIZE;
        return;
    }
    op_1 = get_param_long_value_process(memory, cursor, 1);
    op_2 = get_param_long_value_process(memory, cursor, 2);
    res_register = get_param_value(memory, cursor, 3);
    if (res_register < 1 || res_register > REG_NUMBER)
    {
        cursor->position = (cursor->position + 1) % MEM_SIZE;
        return;
    }
    cursor->registers[res_register] = (*memory)[(op_1 + op_2) % MEM_SIZE];
    dcl_size = get_size_param(type_param, 1) + get_size_param(type_param, 2) + get_size_param(type_param, 3);
    cursor->position = (cursor->position + dcl_size + 2) % MEM_SIZE;
    cursor->registers[0] = (cursor->registers[res_register] == 0) ? 1 : 0;
    bypass_programs(programs, nb_programs);
}
