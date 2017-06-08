/*
** debug.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 08:31:40 2017 MARZI Nicolas
** Last update Thu Jun  8 08:34:37 2017 MARZI Nicolas
*/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "parser.h"

void print_header(header_t *header);
void print_instruction(instruction_t *container);
void print_array(char **container);
void print_label(label_t *container);
void print_line(int number);
void print_param_possibilities(byte type);

#endif