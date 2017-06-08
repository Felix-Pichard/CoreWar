/*
** game.c for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:18:31 2017 MARZI Nicolas
** Last update Thu Jun  8 17:09:50 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "libmy.h"
#include "game.h"
#include "op.h"

void escape_program(game_t *game)
{
    program_t **container;
    // program_t *tmp;
    int i;

    container = game->programs;
    for (i = 0; i < game->nb_player; i++)
    {
        my_put_nbr(container[i]->alive);my_putstr(" -> ");my_put_nbr(container[i]->id);
        my_putstr("\n");
        // if (!game->programs[i]->alive && game->programs[i + 1] != NULL)
        // {
        //     tmp = game->programs[i];
        //     game->programs[i] = game->programs[i + 1];
        //     game->programs[i + 1] = tmp;
        //     i--;
        // }
    }
}

int nb_program(program_t **program)
{
    int size;

    for (size = 0; *program != NULL; program++)
        size++;
    return (size);
}

void init_game(game_t *game)
{
    escape_program(game);
    game->max_cycles = CYCLE_TO_DIE;
    game->left_cycles = game->max_cycles;
    game->nb_player = nb_program(game->programs);
    game->dump_cycles = -1;
}

void launch_game(game_t *game)
{
    int i;
    // cursor_t *current_cursor;

    while (game->nb_player > 1 && game->max_cycles > 0 && game->dump_cycles != 0)
    {
        for (i = 0; i < game->nb_player; i++)
        {
            // current_cursor = game->cursors[i - 1];
            // if (current_cursor->left_cycles == 0)
                my_putstr("exec instruction \n");
            // current_cursor->left_cycles--;
            game->programs[i]->alive = 0;
        }
        if (game->dump_cycles != -1)
            game->dump_cycles--;
        if (game->left_cycles == 0)
        {
            escape_program(game);
            game->max_cycles -= CYCLE_DELTA;
            game->left_cycles = game->max_cycles;
        }
        my_put_nbr(game->max_cycles);my_putstr(" - ");my_put_nbr(game->left_cycles);my_putstr("\n");
        game->left_cycles--;
    }
}

void free_game(game_t *game)
{
    program_t *clean;

    for (; *game->programs != NULL;)
    {
        clean = (*game->programs);
        // free(clean->name);
        free(clean);
        game->programs++;
    }
    // free(game->programs);
}