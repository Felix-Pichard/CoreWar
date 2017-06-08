/*
** param.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 08:38:32 2017 MARZI Nicolas
** Last update Thu Jun  8 08:42:28 2017 MARZI Nicolas
*/

#ifndef __PARAM_H__
#define __PARAM_H__

#include "parser.h"

int is_param_valid(char *arg);
int is_param_label(char *line);
int is_param_register(char *line);
int is_param_indir(char *line);
int is_param_dir(char *line);
char *get_type_param(byte type);

#endif