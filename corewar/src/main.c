/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Thu Jun  8 16:34:41 2017 MARZI Nicolas
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
    program_t **programs;
    programs = malloc(sizeof(program_t) * 4);
    programs[0] =  malloc(sizeof(program_t));
    *programs[0] = (program_t) {1, 1, "test"};
    programs[1] =  malloc(sizeof(program_t));
    *programs[1] = (program_t) {2, 1, "test1"};
    programs[2] =  malloc(sizeof(program_t));
    *programs[2] = (program_t) {3, 1, "test2"};
    programs[3] =  malloc(sizeof(program_t));
    programs[3] = NULL;

    game_t game;
    game.programs = programs;

    init_game(&game);
    launch_game(&game);
    free_game(&game);

    my_put_nbr(nb_program_alive(programs));

    return (0);
    
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
