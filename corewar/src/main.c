/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Sun Jun 11 10:48:09 2017 MARZI Nicolas
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
    t_meta *program;
    game_t game;
    int i;
    int j;

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
        for (j = 1; j <= REG_NUMBER; j++)
            game.cursors[i].registers[i] = 0;
        game.cursors[i].position = program->programs[i].address;
        game.cursors[i].cycles_left = 0;
    }
    init_game(&game);
    launch_game(&game, program->interactive_mode);
    free_game(&game);
    return (0);
}
