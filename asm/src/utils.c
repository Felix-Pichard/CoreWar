/*
** utils.c for FDI-COBJ in /media/maniarr/Workspace1/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Sun Jun 11 13:28:20 2017 MARZI Nicolas
** Last update Sun Jun 11 15:30:32 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "op.h"
#include "libmy.h"

int is_comment(char *line)
{
    return (line[0] == COMMENT_CHAR);
}

int array_len(char **array)
{
    int size;

    for(size = 0; array[size] != NULL; size++)
    {}
    return (size);
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

op_t get_op(char *name)
{
    int i;

    for (i = 0; i < 15; i++)
    {
        if (my_strcmp(name, op_tab[i].mnemonique) == 0)
            return (op_tab[i]);
    }
    return (op_tab[15]);
}

