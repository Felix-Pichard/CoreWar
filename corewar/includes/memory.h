/*
** memory.h for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Thu Jun  8 18:51:40 2017 MARZI Nicolas
*/

#ifndef _MEMORY__H_
#define _MEMORY__H_

#include "op.h"
#include "parser.h"

typedef unsigned char byte;

void init_mem(byte **memory);
int dump_n(byte memory[], int n);
int dump(byte memory[]);
// void insert_prog(t_program program, byte *memory[], int offset);

#endif
