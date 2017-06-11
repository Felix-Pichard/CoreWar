/*
** instructions_utils.c for FDI-COBJ in /media/maniarr/Workspace1/etna/CoreWar/corewar/src/instructions
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Fri Jun  9 10:02:12 2017 MARZI Nicolas
** Last update Sun Jun 11 10:55:49 2017 MARZI Nicolas
*/

#include "memory.h"
#include "instructions.h"
#include "op.h"
#include "game.h"

void bypass_programs(program_t *program[], int nb_programs)
{
    nb_programs = program[0]->alive;
    ++nb_programs;
}

op_t get_op(byte opcode)
{
    int i;

    for (i = 0; i < 11; i++)
    {
        if (op_tab[i].code == opcode)
            return (op_tab[i]);
    }
    return (op_tab[15]);
}

int get_nb_param(byte type_param)
{
    int i;
    int size;

    size = 0;
    for (i = 0; i < 4;i ++)
    {
        if ((type_param & (0x03 << (i * 2))) != 0)
            size++;
    }
    return (size);
}

int get_param_valid_value(byte type_param, int i)
{
    byte tmp;

    tmp = (type_param >> (8 - i*2)) & 0x03;
    if (tmp == 1)
        return (T_REG);
    else if (tmp == 2)
        return (T_IND);
    return (T_DIR);
}

int is_type_param_valid(byte opcode, byte type_params)
{
    op_t op;
    int i;

    op = get_op(opcode);
    if (op.code != opcode)
        return (0);

    if (get_nb_param(type_params) != op.nbr_args)
        return (0);
    
    for (i = 1; i <= op.nbr_args; i++)
    {
        if (((byte) op.type[i] & get_param_valid_value(type_params, i)) == 0)
            return (0);
    }
    return (1);
}

int read_byte_to_int(byte *memory[], int position, int size)
{
    int i;
    int result;

    result = 0;
    for (i = 0; i < size; i++)
        result += (*memory)[position + i] << ((size - i - 1) * 8);
    return (result);
}

int get_size_param(byte type_param, int i)
{
    byte type;

    type = (type_param >> ((4 - i) * 2)) & 3;
    if (type == CODED_REG)
        return (T_REG);
    else if (type == CODED_DIR)
        return (DIR_SIZE);
    else if (type == CODED_IND)
        return (IND_SIZE);
    return (0);
}

int get_param_value(byte *memory[], cursor_t *cursor, int i_param)
{
    int i;
    int type_param;
    int value;
    int position;

    value = 0;
    position = cursor->position;
    position = (position + 1) % MEM_SIZE;
    type_param = (*memory)[position];
    for (i = 1; i < i_param; i++)
        position = (position + get_size_param(type_param, i)) % MEM_SIZE;
    position = (position + 1) % MEM_SIZE;
    value = read_byte_to_int(memory, position, get_size_param(type_param, i_param));

    return (value);        
}

int get_param_value_process(byte *memory[], cursor_t *cursor, int i_param)
{
    int i;
    int type_param;
    int value;
    int position;

    position = cursor->position;
    position = (position + 1) % MEM_SIZE;
    type_param = (*memory)[position];
    for (i = 1; i < i_param; i++)
        position = (position + get_size_param(type_param, i)) % MEM_SIZE;
    position = (position + 1) % MEM_SIZE;
    value = read_byte_to_int(memory, position, get_size_param(type_param, i_param));
    if (((type_param >> (4 - i) * 2) & 3) == CODED_DIR)
        return (value);
    if (((type_param >> (4 - i) * 2) & 3) == CODED_REG && value >= 1 && value <= REG_NUMBER)
        return (cursor->registers[value]);
    else if (((type_param >> (4 - i) * 2) & 3) == CODED_IND)
        return ((*memory)[value % MEM_SIZE]);
    return (0);        
}