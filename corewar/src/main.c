/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Thu Jun  8 16:25:48 2017 MARZI Nicolas
*/

#include "libmy.h"
#include "parser.h"
#include "op.h"
#include "manager.h"
#include "memory.h"
#include "header_parser.h"
#include "game.h"

int main(int argc, char **argv)
{    
    byte *mem;
    t_meta *program;

    get_file_content("../asm/test.cor", 4);
    return (0);
    
    program = parser(argc, argv);
    mem = init_mem();
    print_tab(program);
    try_put_programs(program);
    free(mem);
    return (0);
}
