/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#ifndef _PARSER__H_
#define _PARSER__H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "libmy.h"

 
typedef struct          s_program
{
    char*               prog_name;
    int                 number;
    int                 address;
    int                 cycle_of_instruction;
    int                 cycle_spent;
    header_t            header;
}                       t_program;

typedef struct          s_meta
{
    int nbr_prg;
    t_program* programs;
}                       t_meta;

void    print_tab(t_meta* test);
void    fill_struct(int argc, char** argv, t_meta *test);
void    init_meta(t_meta *meta);
t_meta* parser(int argc, char** argv);

#endif
