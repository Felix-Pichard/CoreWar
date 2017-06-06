/*
** parser.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 20:02:00 2017 MARZI Nicolas
** Last update Mon Jun  5 20:02:00 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "op.h"
#include "parser.h"
#include "libmy.h"

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

int is_char_label(char c)
{
    int i;

    for (i = 0; i < my_strlen(LABEL_CHARS); i++)
    {
        if (c == LABEL_CHARS[i])
            return (1);
    }
    return (0);
}

int is_label(char *line)
{
    int cursor;

    for (cursor = 0; *(line + cursor) != '\0'; cursor++)
    {
        if (line[cursor] == LABEL_CHAR && cursor > 0)
            return (1);
        else if (is_char_label(line[cursor]) == 0)
            return (0);
    }
    return (0);
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

int is_param_label(char *line)
{
    char c;

    for (; *line != '\0'; line++)
    {
        c = *line;
        if (!is_char_label(c))
            return (0);
    }
    return (1);
}

int is_param_register(char *line)
{
    if (line[0] != 'r')
        return (0);
    line++;
    return (is_nbr(line));
}

int is_param_indir(char *line)
{
    return (is_nbr(line));
}

int is_param_dir(char *line)
{
    if (line[0] != DIRECT_CHAR)
        return (0);
    line++;
    if (line[0] == LABEL_CHAR)
    {
        line++;
        if (is_param_label(line))
            return (1);
    }
    else if (is_nbr(line))
        return (1);
    return (0);    
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

int set_command(char *line)
{
    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
    {
        my_putstr("Command name: ");
        line = line + my_strlen(NAME_CMD_STRING);
        escape_str(line);
        return (1);
    }
    else if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0)
    {
        my_putstr("Command comment: ");
        line = line + my_strlen(COMMENT_CMD_STRING);
        escape_str(line);
        return (1);
    }
    my_putstr(line);my_putstr("\n");
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

int is_param_valid(char *arg)
{
    return (is_param_register(arg) || is_param_dir(arg) || is_param_indir(arg));
}

void init_container_buffer(char **buffer, int size)
{
    int i;

    for (i = 0; i < size;i++)
        *(buffer + i) = 0;
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
        return (0x01);
    else if (is_param_dir(line))
        return (0x02);
    else if (is_param_indir(line))
        return (0x03);
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
        if (param->type == 0x01)
        {
            param->value = my_getnbr(split_str(lines[i], 'r')[0]);
        }
        else if (param->type == 0x03)
        {
            param->value = my_getnbr(lines[i]);
        }
        else
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
    }
    return (1);
}

int set_instruction(char *line)
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
        return (0);

    if (!set_params(&instruction, params, op.nbr_args))
        return (0);

    instruction.opcode = (byte) op.code;
    instruction.nb_args = (byte) op.nbr_args;
    instruction.next = NULL;

    my_putstr("Instruction : ");my_putstr(instructions[0]);my_putstr("\n");
    for (int i = 0; i < op.nbr_args; i++)
    {
        my_putstr("argument: ");my_put_nbr((int) instruction.args[i].type);
        my_putstr(" ");
        
        if (instruction.args[i].label != NULL)
            my_putstr(instruction.args[i].label);
        else
            my_put_nbr(instruction.args[i].value);
        my_putstr("\n");
    }
    return (1);
}

int set_label(char *line)
{
    char **labels;

    labels = split_str(line, ':');
    if (array_len(labels) == 2)
    {
        my_putstr("Label defined: "); my_putstr(labels[0]); my_putstr("\n");
        if (is_instruction(labels[1]))
            return (set_instruction(labels[1]));
    }
    return (0);
}