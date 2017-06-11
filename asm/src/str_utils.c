/*
** str_utils.c for FDI-COBJ in /media/maniarr/Workspace1/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Sun Jun 11 13:29:00 2017 MARZI Nicolas
** Last update Sun Jun 11 13:37:26 2017 MARZI Nicolas
*/

#include "op.h"
#include "parser.h"
#include "libmy.h"
#include "assemble.h"

char *duplicate_str(char *string)
{
    char *result;
    int i;
    int size;
    
    size = my_strlen(string);
    result = safe_malloc(sizeof(char) * (size + 1));
    for (i = 0; i < size; i++)
        result[i] = string[i];
    result[i + 1] = '\0';
    return (result);
}

char **split_str(char *line, char delimiter)
{
    char **result;
    char buffer[128];
    int cursor;
    char *str;

    init_buffer(buffer, 128);
    result = safe_malloc(sizeof(char *) * (find_occurence(line, delimiter) + 2));
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

char **split_n_str(char *line, char delimiter, int i)
{
    char **result;
    char buffer[128];
    int cursor;
    char *str;

    init_buffer(buffer, 128);
    result = safe_malloc(sizeof(char *) * (find_occurence(line, delimiter) + 2));
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

void escape_str(char *string)
{
    int size;
    int i;

    size = my_strlen(string);
    while (is_invisible_char(string[0]))
    {
        for (i = 0; i < size - 1 && !is_invisible_char(string[i + 1]); i++)
            string[i] = string[i + 1];
        string[size - 1] = '\0';
    }
}

char *get_string(char *buffer)
{
    int size;
    char *result;
    int i;

    size = my_strlen(buffer);
    result = safe_malloc(sizeof(char) * size);
    for (i = 0; i < size; i++)
        result[i] = buffer[i];
    result[size] = '\0';
    escape_str(result);
    return (result);
}

void push_str(char **container, char *item)
{
    escape_str(item);
    if (my_strlen(item) > 0)
        container[array_len(container)] = item;
}