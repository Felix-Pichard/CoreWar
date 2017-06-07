/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include "libmy.h"
#include "parser.h"
#include "op.h"
#include "memory.h"

int main(int argc, char **argv)
{
    t_byte *mem;
    t_meta *meta;

    meta = parser(argc, argv);
    mem = init_mem();
    print_tab(meta);
    free(mem);
    return (0);
}
