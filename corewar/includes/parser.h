/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Thu Jun  8 19:42:22 2017 MARZI Nicolas
*/

#ifndef _PARSER__H_
#define _PARSER__H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "libmy.h"
#include "memory.h"

typedef struct          s_meta
{
    int nbr_prg;
    t_program *programs;
}                       t_meta;

void    print_tab(t_meta* test);
void    fill_struct(int argc, char** argv, t_meta *test);
void    init_meta(t_meta *meta);
t_meta* parser(int argc, char** argv);

#endif
