/*
** param.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 08:38:12 2017 MARZI Nicolas
** Last update Thu Jun  8 08:42:01 2017 MARZI Nicolas
*/

#include "op.h"
#include "param.h"
#include "parser.h"
#include "label.h"

int is_param_valid(char *arg)
{
    return (is_param_register(arg) || is_param_dir(arg) || is_param_indir(arg));
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

char *get_type_param(byte type)
{
    char *param_name[3] = {
        "register",
        "direct",
        "indirect"
    };
    if (type >= 1 && type <= 3)
        return (param_name[type - 1]);
    return ("unknow");
}