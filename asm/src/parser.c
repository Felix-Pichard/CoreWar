/*
** parser.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 20:02:00 2017 MARZI Nicolas
** Last update Thu Jun  8 08:43:19 2017 MARZI Nicolas
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

int is_comment(char *line)
{
    return (line[0] == COMMENT_CHAR);
}

int is_command(char *line)
{
    return (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0 ||
            my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0);
}

int array_len(char **array)
{
    int size;

    for(size = 0; array[size] != '\0'; size++) 
    {}
    return (size);
}

int is_instruction(char *line)
{
    int cursor;

    for (cursor = 0; cursor < 11; cursor++)
    {
        if (my_strncmp(line, op_tab[cursor].mnemonique, my_strlen(op_tab[cursor].mnemonique)) != 0)
            continue;
        else if (line[my_strlen(op_tab[cursor].mnemonique)] == ' ')
            return (1);
    }
    return (0);
}

int is_null(char *line)
{
    return (my_strlen(line) == 0);
}

int is_nbr(char *line)
{
    char c;

    for (; *line != '\0'; line++)
    {
        c = *line;
        if (!(c >= '0' && c <= '9'))
            return (0);
    }
    return (1);    
}

int is_invisible_char(char c)
{
    return (c == ' ' || c == '\t');
}

void escape_str(char *string)
{
    int size;

    size = my_strlen(string);
    while (is_invisible_char(string[0]))
    {
        for (int i = 0; i < size - 1; i++)
            string[i] = string[i + 1];
        string[size - 1] = '\0';
    }
}

int set_command(char *line, script_t *script)
{
    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
    {
        line = line + my_strlen(NAME_CMD_STRING);
        escape_str(line);
        my_strcpy(script->header.prog_name, line);
        return (1);
    }
    else if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0)
    {
        line = line + my_strlen(COMMENT_CMD_STRING);
        escape_str(line);
        my_strcpy(script->header.comment, line);
        return (1);
    }
    return (0);
}

int find_occurence(char *line, char find)
{
    int occurence;

    for (occurence = 0; *line != '\0'; line++)
    {
        if (*line == find)
            occurence++;
    }
    return (occurence);
}

void init_buffer(char *buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(buffer + i) = '\0';
    }
}

char *get_string(char *buffer)
{
    int size;
    char *result;

    size = my_strlen(buffer);
    result = malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
        result[i] = buffer[i];
    result[size] = '\0';
    escape_str(result);
    return (result);
}

void push_str(char **container, char *item)
{
    if (my_strlen(item) > 0)
        container[array_len(container)] = item;
}

void init_container_buffer(char **buffer, int size)
{
    int i;

    for (i = 0; i < size;i++)
        *(buffer + i) = 0;
}

char **split_n_str(char *line, char delimiter, int i)
{
    char **result;
    char buffer[128];
    int cursor;
    char *str;

    init_buffer(buffer, 128);
    result = malloc(sizeof(char *) * (find_occurence(line, delimiter) + 2));
    init_container_buffer(result, array_len(result));

    for (cursor = 0; *line != '\0'; line++)
    {
        if (*line == delimiter && i != 0)
        {
            i--;
            str = get_string(buffer);
            if (my_strlen(str) > 0)
                push_str(result, str);
            init_buffer(buffer, 128);
            cursor = 0;
        }
        else
            buffer[cursor++] = *line;
    }
    str = get_string(buffer);
    if (my_strlen(str) > 0)
        push_str(result, str);
    return (result);
}

char **split_str(char *line, char delimiter)
{
    char **result;
    char buffer[128];
    int cursor;
    char *str;

    init_buffer(buffer, 128);
    result = malloc(sizeof(char *) * (find_occurence(line, delimiter) + 2));
    init_container_buffer(result, array_len(result));

    for (cursor = 0; *line != '\0'; line++)
    {
        if (*line == delimiter)
        {
            str = get_string(buffer);
            if (my_strlen(str) > 0)
                push_str(result, str);
            init_buffer(buffer, 128);
            cursor = 0;
        }
        else
            buffer[cursor++] = *line;
    }
    str = get_string(buffer);
    if (my_strlen(str) > 0)
        push_str(result, str);
    return (result);
}

op_t get_op(char *name)
{
    int i;

    for (i = 0; i < 11; i++)
    {
        if (my_strcmp(name, op_tab[i].mnemonique) == 0)
            return (op_tab[i]);
    }
    return ((op_t) {0, 0, {0}, 0, 0, 0});
}

byte get_param_code(char *line)
{
    if (is_param_register(line))
        return (CODED_REG);
    else if (is_param_dir(line))
        return (CODED_DIR);
    else if (is_param_indir(line))
        return (CODED_IND);
    return (0x00);
}

int set_params(instruction_t *instruction, char **lines, int size)
{
    int i;
    char *label;
    param_t *param;

    for (i = 0; i < size; i++)
    {
        param = &(instruction->args[i]);
        if (!is_param_valid(lines[i]))
            return (0);
        *param = (param_t) {NULL, 0, get_param_code(lines[i])};
        if (param->type == CODED_REG)
        {
            param->value = my_getnbr(split_str(lines[i], 'r')[0]);
        }
        else if (param->type == CODED_IND)
        {
            param->value = my_getnbr(lines[i]);
        }
        else if (param->type == CODED_DIR)
        {
            label = split_str(lines[i], '%')[0];
            if (label[0] == ':')
            {
                label = split_str(label, ':')[0];
                param->label = label;
            }
            else
                param->value = my_getnbr(label);
        }
        else
            return (0);
    }
    return (1);
}

int set_instruction(char *line, script_t *script)
{
    char **instructions;
    char **params;
    op_t op;
    instruction_t instruction;

    instructions = split_str(line, ' ');

    if (array_len(instructions) != 2)
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

    for (int i = 0; i < instruction.nb_args; i++)
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
    add_instruction(script, instruction);
    return (1);
}

char *duplicate_str(char *string)
{
    char *result;
    int i;
    int size;
    size = my_strlen(string);
    result = malloc(sizeof(char) * (size + 1));
    for (i = 0; i < size; i++)
        result[i] = string[i];
    result[i + 1] = '\0';
    return (result);
}

int set_label(char *line, script_t *script)
{
    char **labels;
    label_t item;

    labels = split_n_str(line, ':', 1);
    if (array_len(labels) == 2)
    {
        item = (label_t) {duplicate_str(labels[0]), get_rec_size(script->instruction), NULL};
        add_label(script, item);
        if (is_instruction(labels[1]))
            return (set_instruction(labels[1], script));
    }
    free_array(labels);
    return (0);
}