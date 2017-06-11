/*
** instruction.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 10:35:55 2017 MARZI Nicolas
** Last update Sun Jun 11 15:29:57 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "libmy.h"
#include "instruction.h"
#include "parser.h"
#include "byte.h"

int is_instruction(char *line)
{
    int cursor;

    for (cursor = 0; cursor < 15; cursor++)
    {
        if (my_strncmp(line, op_tab[cursor].mnemonique, my_strlen(op_tab[cursor].mnemonique)) != 0)
            continue;
        else if (line[my_strlen(op_tab[cursor].mnemonique)] == ' ')
            return (1);
    }
    return (0);
}

void add_instruction(script_t *script, instruction_t item)
{
    instruction_t *tmp;

    if (script->instruction == NULL)
    {
        script->instruction = safe_malloc(sizeof(instruction_t));
        *script->instruction = item;
        script->instruction->next = NULL;
        return;
    }
    tmp = script->instruction;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = safe_malloc(sizeof(instruction_t));
    *tmp->next = item;
}

byte get_param_byte(instruction_t instruction)
{
    int i;
    byte result;
    param_t arg;

    result = 0;
    for (i = 0; i < instruction.nb_args; i++)
    {
        arg = instruction.args[i];
        result = result | (arg.type << ((4 - i - 1) * 2));
    }
    return (result);
}

int get_size(instruction_t instruction)
{
    int i;
    int size;
    byte type;

    type = 0;
    size = 1;
    if (instruction.opcode != 1 && instruction.opcode != 9)
        size++;
    for (i = 0; i < instruction.nb_args; i++)
    {
        type = instruction.args[i].type;
        if (instruction.opcode == 11 && (i > 0))
            size += IND_SIZE;
        else if (instruction.opcode == 9)
            size += IND_SIZE;
        else if (type == CODED_REG)
            size += T_REG;
        else if (type == CODED_DIR)
            size += DIR_SIZE;
        else if (type == CODED_IND)
            size += IND_SIZE;
    }
    return (size);
}

int get_rec_size(instruction_t *instruction)
{
    instruction_t *tmp;
    int size;

    tmp = instruction;
    size = 0;
    if (instruction == NULL)
        return (size);
    while (tmp->next != NULL)
    {
        size += get_size(*tmp);
        tmp = tmp->next;
    }
    size += get_size(*tmp);
    return (size);
}

int get_size_param(byte type)
{
    if (type == CODED_REG)
        return (T_REG);
    else if (type == CODED_DIR)
        return (DIR_SIZE);
    else if (type == CODED_IND)
        return (IND_SIZE);
    return (0);
}

int write_instruction(byte *buffer, int offset, instruction_t *instruction)
{
    int i;
    int j;
    int add;
    int size_param;
    byte *tmp;
    param_t param;

    i = 0;
    add = 0;
    tmp = NULL;
    buffer[offset] = instruction->opcode;
    add++;
    if (instruction->opcode != 1 && instruction->opcode != 9 && instruction->opcode != 11)
    {
        buffer[offset + add] = get_param_byte(*instruction);
        add++;
        for (i = 0; i < instruction->nb_args; i++)
        {
            param = instruction->args[i];
            size_param = get_size_param(param.type);
            tmp = int_to_byte(param.value, size_param);
            for (j = 0; j < size_param; j++)
            {
                buffer[offset + add] = tmp[j];
                add++;
            }
            free(tmp);
        }
    }
    else if (instruction->opcode == 1)
    {
        size_param = 4;
        tmp = int_to_byte(instruction->args[0].value, size_param);
        for (j = 0; j < size_param; j++)
        {
            buffer[offset + add] = tmp[j];
            add++;
        }
        free(tmp);
    }
    else if (instruction->opcode == 9)
    {
        size_param = IND_SIZE;
        tmp = int_to_byte(instruction->args[0].value, size_param);
        for (j = 0; j < size_param; j++)
        {
            buffer[offset + add] = tmp[j];
            add++;
        } 
        free(tmp);
    }
    else if (instruction->opcode == 11)
    {
        buffer[offset + add] = get_param_byte(*instruction);
        add++;
        for (i = 0; i < instruction->nb_args; i++)
        {
            param = instruction->args[i];
            size_param = get_size_param(param.type);
            tmp = int_to_byte(param.value, i == 0 ? size_param : IND_SIZE);
            for (j = 0; j < (i == 0 ? size_param : IND_SIZE); j++)
            {
                buffer[offset + add] = tmp[j];
                add++;
            }
            free(tmp);
        }
    }
    return (add);
}