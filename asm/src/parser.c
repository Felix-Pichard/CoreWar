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

int is_label(char *line)
{
    int cursor;

    for (cursor = 0; *(line + cursor) != '\0'; cursor++)
    {
        if (line[cursor] == LABEL_CHAR && cursor > 0)
            return (1);
        else if (my_strstr(&line[cursor], LABEL_CHARS) == 0)
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

int is_param_dir(char *line)
{
    return (is_nbr(line));
}

int is_param_indir(char *line)
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

void set_command(char *line)
{
    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
    {
        my_putstr("Command name: ");
        line = line + my_strlen(NAME_CMD_STRING);
        escape_str(line);
    }
    else if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0)
    {
        my_putstr("Command comment: ");
        line = line + my_strlen(COMMENT_CMD_STRING);
        escape_str(line);
    }

    my_putstr(line);my_putstr("\n");
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

    size = my_strlen(buffer) + 1;
    result = malloc(sizeof(char) * size);
    for (int i = 0; i < size -1; i++)
        result[i] = buffer[i];
    result[size - 1] = '\0';
    escape_str(result);
    return (result);
}

void push_str(char **container, char *item)
{
    container[array_len(container)] = item;
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

    init_buffer(buffer, 128);
    result = malloc(sizeof(char **) * find_occurence(line, delimiter) + 1);
    init_container_buffer(result, find_occurence(line, delimiter) + 1);
    for (;*line != '\0'; line++)
    {
        if (*line == delimiter)
        {
            push_str(result, get_string(buffer));
            init_buffer(buffer, 128);
        }
        else
            buffer[my_strlen(buffer)] = *line;
    }
    push_str(result, get_string(buffer));
    return (result);
}

void set_label(char *line)
{
    char **labels;

    labels = split_str(line, ':');
    if (array_len(labels) == 2)
    {
        my_putstr("Label defined: "); my_putstr(labels[0]); my_putstr("\n");
    }
    // todo exit
}

void set_instruction(char *line)
{
    
}