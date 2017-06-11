/*
** param.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 08:38:12 2017 MARZI Nicolas
** Last update Sun Jun 11 18:17:57 2017 MARZI Nicolas
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
    char **tmp;

    for (i = 0; i < size; i++)
    {
        param = &(instruction->args[i]);
        if (!is_param_valid(lines[i]))
            return (0);
        (*param).label = NULL;
        (*param).value = 0;
        (*param).type = get_param_code(lines[i]);
        if (param->type == CODED_REG)
        {
            tmp = split_str(lines[i], 'r');
            param->value = my_getnbr(tmp[0]);
            free(tmp);
        }
        else if (param->type == CODED_IND)
        {
            param->value = my_getnbr(lines[i]);
        }
        else if (param->type == CODED_DIR)
        {

            tmp = split_str(lines[i], '%');
            label = tmp[0];
            if (label[0] == ':')
            {
                free(tmp);
                tmp = split_str(label, ':');
                label = tmp[0];
                param->label = label;
            }
            else
                param->value = my_getnbr(label);
            free(tmp);
        }
        else
            return (0);
    }
    return (1);
}