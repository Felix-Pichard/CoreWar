/*
** memory.h for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Sun Jun 11 10:48:53 2017 MARZI Nicolas
*/

#ifndef _MEMORY__H_
#define _MEMORY__H_

#include "op.h"
#include "libmy.h"
 
typedef struct          s_program
{
    char*               file_name;
    int                 number;
    int                 address;
    byte*               binaries;
    header_t            header;
}                       t_program;


void init_mem(byte **memory);
int dump_n(byte memory[], int n);
int dump(byte memory[]);
void insert_prog(t_program program, byte *memory[], int offset);

#endif
