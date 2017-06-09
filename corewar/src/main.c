/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Fri Jun  9 09:23:00 2017 MARZI Nicolas
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
    // program_t **programs;
    // programs = malloc(sizeof(program_t) * 4);
    // programs[0] =  malloc(sizeof(program_t));
    // *programs[0] = (program_t) {1, 1, "test"};
    // programs[1] =  malloc(sizeof(program_t));
    // *programs[1] = (program_t) {2, 1, "test1"};
    // programs[2] =  malloc(sizeof(program_t));
    // *programs[2] = (program_t) {3, 1, "test2"};
    // programs[3] =  malloc(sizeof(program_t));
    // programs[3] = NULL;

    // game_t game;
    // game.programs = programs;

    // init_game(&game);
    // launch_game(&game);
    // free_game(&game);

    // my_put_nbr(nb_program_alive(programs));

    // return (0);

    t_meta *program;
    game_t game;int i;

    program = parser(argc, argv);
    game.memory = malloc(sizeof(byte) * MEM_SIZE);

    init_mem(&game.memory);
    
    game.nb_player = program->nbr_prg;
    
    game.programs = malloc(sizeof(program_t) * game.nb_player);
    game.cursors = malloc(sizeof(cursor_t) * game.nb_player);
    for (i = 0; i < program->nbr_prg; i++)
    {
        insert_prog(program->programs[i], &game.memory, (MEM_SIZE / program->nbr_prg) * i);
        game.programs[i].id = i;
        game.programs[i].alive = 0;
        game.programs[i].name = program->programs[i].header.prog_name;
        game.cursors[i].registers[0] = i + 1;
        for (int j = 1; j <= REG_NUMBER; j++)
            game.cursors[i].registers[i] = 0;
        game.cursors[i].position = program->programs[i].address;
        game.cursors[i].cycles_left = 0;
    }
    dump(game.memory);

    init_game(&game);
    // launch_game(&game);
    // free_game(&game);

    return (0);
}
