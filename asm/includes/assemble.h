/*
** assemble.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 13:47:22 2017 MARZI Nicolas
** Last update Sun Jun 11 13:32:59 2017 MARZI Nicolas
*/

#ifndef __ASSEMBLE_H__
#define __ASSEMBLE_H__

#include "parser.h"

int assemble(script_t *script);
char *duplicate_str(char *string);
char **split_str(char *line, char delimiter);
char **split_n_str(char *line, char delimiter, int i);
void escape_str(char *string);
char *get_string(char *buffer);
void push_str(char **container, char *item);

#endif