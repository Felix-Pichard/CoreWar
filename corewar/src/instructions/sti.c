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

void sti(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    byte type_param;
    int value;
    int op_1;
    int op_2;
    int i;
    int dcl_size;

    type_param = (*memory)[cursor->position + 1];
    if (!is_type_param_valid(0x0b, type_param))
    {
        cursor->position = (cursor->position + 1) % MEM_SIZE;
    my_putstr(": inex \n ");
        return;
    }
    my_put_nbr(value = get_param_value_process(memory, cursor, 1));
    my_put_nbr(op_1 = get_param_value_process(memory, cursor, 2));
    my_put_nbr(op_2 = get_param_value_process(memory, cursor, 3));
    my_put_nbr(op_2 + op_1);
    my_putstr(": index \n ");
        for (i = 0; i < 4; i++) 
            (*memory)[op_2 + op_1] = (byte) value >> ((MAX_ARGS_NUMBER - i - 1) * 8);
    dcl_size = get_size_param(type_param, 1) + get_size_param(type_param, 2) + get_size_param(type_param, 3);
    cursor->position = (cursor->position + dcl_size + 2) % MEM_SIZE;
    bypass_programs(programs, nb_programs);
}
