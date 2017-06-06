/*
** header.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#ifndef _HEADER_H_
    #define _HEADER_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../libmy/libmy.h"

 
typedef struct          s_program
{
    char*               prog_name;
    int                 number;
    int                 address;
}                       s_program;
 
 #endif
