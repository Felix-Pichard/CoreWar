/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include <malloc.h>
#include "libmy.h"
#include "../../sujet/op.h"
#include "../includes/memory.h"

int main(int argc, char **argv)
{
    t_byte *mem;
    mem = init_mem();
    free(mem);
    return (0);
}
