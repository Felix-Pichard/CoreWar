/*
** instruction.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 10:36:27 2017 MARZI Nicolas
** Last update Thu Jun  8 07:52:12 2017 MARZI Nicolas
*/

#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "parser.h"

void add_instruction(script_t *script, instruction_t item);
void print_instruction(instruction_t *container);
int get_size(instruction_t instruction);
int get_rec_size(instruction_t *instruction);
int get_size(instruction_t instruction);
void print_byte(byte b);
byte get_param_byte(instruction_t instruction);
byte *int_to_byte(int n, int size);
int write_instruction(byte *buffer, int offset, instruction_t *instruction);

#endif