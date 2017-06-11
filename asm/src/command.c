/*
** command.c for FDI-COBJ in /media/maniarr/Workspace1/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Sun Jun 11 13:41:07 2017 MARZI Nicolas
** Last update Sun Jun 11 13:42:29 2017 MARZI Nicolas
*/

#include "libmy.h"
#include "parser.h"
#include "op.h"

int is_command(char *line)
{
    return (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0 ||
            my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0);
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