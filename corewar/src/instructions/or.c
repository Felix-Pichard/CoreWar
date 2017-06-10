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

void i_or(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    int op_1;
    int op_2;
    int res_reg;
    int res;

    if (!is_type_param_valid(7, *memory[cursor->position + 1]))
    {
        ++(cursor->position);
        return;
    }
    op_1 = *memory[cursor->position + 2];
    op_2 = *memory[cursor->position + 3];
    res_reg = *memory[cursor->position + 4];
    if (op_1 <= REG_NUMBER && op_2 <= REG_NUMBER && res_reg <= REG_NUMBER)
    {
        res = cursor->registers[op_1] | cursor->registers[op_2];
        cursor->registers[res_reg] = res;
        if (res == 0)
            cursor->registers[0] = 1;
        else
            cursor->registers[0] = 0;
    }
    bypass_programs(programs, nb_programs);
}
