/*
** instructions_utils.c for FDI-COBJ in /media/maniarr/Workspace1/etna/CoreWar/corewar/src/instructions
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Fri Jun  9 10:02:12 2017 MARZI Nicolas
** Last update Fri Jun  9 16:53:29 2017 MARZI Nicolas
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
    return ((op_t) {0, 0, {0}, 0, 0, 0});
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

int is_type_param_valid(byte opcode, byte type_params)
{
    op_t op;
    int i;

    op = get_op(opcode);
    if (op.code != opcode)
        return (0);

    if (get_nb_param(type_params) != op.nbr_args)
        return (0);
    
    for (i = 0; i < op.nbr_args; i++)
    {
        if (((byte) op.type[i]) == 0)
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

    type = (type_param >> ((MAX_ARGS_NUMBER - i) * 2)) & 3;
    if (type == CODED_REG)
        return (T_REG);
    else if (type == CODED_DIR)
        return (DIR_SIZE);
    else if (type == CODED_IND)
        return (IND_SIZE);
    return (0);
}