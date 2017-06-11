/*
** parser.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 20:02:00 2017 MARZI Nicolas
** Last update Sun Jun 11 18:32:55 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "op.h"
#include "parser.h"
#include "libmy.h"
#include "label.h"
#include "instruction.h"
#include "free.h"
#include "param.h"
#include "debug.h"

void init_buffer(char *buffer, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        *(buffer + i) = '\0';
    }
}

void init_container_buffer(char **buffer, int size)
{
    int i;

    for (i = 0; i < size;i++)
        *(buffer + i) = 0;
}


int set_instruction(char *line, script_t *script)
{
    char **instructions;
    char **params;
    
    op_t op;
    instruction_t instruction;
    int i;

    instructions = split_str(line, ' ');
    if (array_len(instructions) < 2)
        return (0);
    op = get_op(instructions[0]);
    if (op.mnemonique == NULL)
        return (0);
    params = split_str(instructions[1], SEPARATOR_CHAR);
    if (array_len(params) != op.nbr_args)
    {
        my_put_nbr(array_len(params));my_putstr(" parameters given, ");
        my_put_nbr(op.nbr_args);my_putstr(" expected");
        return (0);
    }
    if (!set_params(&instruction, params, op.nbr_args))
        return (0);
    instruction.opcode = op.code;
    instruction.nb_args = op.nbr_args;
    instruction.next = NULL;
    for (i = 0; i < instruction.nb_args; i++)
    {
        if (((byte) op.type[i] & instruction.args[i].type) == 0)
        {
            my_putstr("Wrong type for ");my_putstr(op.mnemonique);my_putstr(" instruction for parameter at position ");
            my_put_nbr(i + 1);my_putstr("\n");
            my_putstr(get_type_param(instruction.args[i].type));
            my_putstr(" given, expected: ");
            print_param_possibilities(op.type[i]);
            return (0);
        }
    }
    free(instructions);
    add_instruction(script, instruction);
    return (1);
}