/*
** label.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 08:50:33 2017 MARZI Nicolas
** Last update Thu Jun  8 08:44:07 2017 MARZI Nicolas
*/

#ifndef __LABEL_H__
#define __LABEL_H__

#include "parser.h"

label_t *get_label(label_t *container, char *name);
int replace_label(label_t *labels, param_t *param, int offset);
void add_label(script_t *script, label_t item);
void print_label(label_t *container);
int is_char_label(char c);
int is_label(char *line);

#endif