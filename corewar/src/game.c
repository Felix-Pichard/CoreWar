/*
** game.c for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:18:31 2017 MARZI Nicolas
** Last update Thu Jun  8 16:25:21 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "libmy.h"
#include "game.h"

void escape_program(game_t *game)
{
    program_t **container;
    program_t **old;
    program_t *tmp;
    int i;

    old = game->programs;
    game->nb_player = nb_program_alive(game->programs);
    container = malloc(sizeof(program_t) * game->nb_player);
    for (i = 0; *old != NULL;)
    {
        if (!(*old)->alive)
        {
            tmp = (*old);
            old++;
            free(tmp->name);
            free(tmp);
            continue;
        }
        container[i] = malloc(sizeof(program_t));
        container[i] = *old;
        i++;
        old++;
    }
    free(game->programs);
    game->programs = container;
}

void init_game(game_t *game)
{
    escape_program(game);
    game->left_cycles = game->max_cycles;
}

void launch_game(game_t *game)
{
    int i;
    // cursor_t *current_cursor;

    while (nb_program_alive(game->programs) > 0 && game->max_cycles > 0 && game->dump_cycles != 0)
    {
        for (i = 0; i < game->nb_player; i++)
        {
            // current_cursor = game->cursors[i - 1];
            // if (current_cursor->left_cycles == 0)
                my_putstr("exec instruction \n");
            // current_cursor->left_cycles--;
        }
        if (game->dump_cycles != -1)
            game->dump_cycles--;
        if (game->left_cycles == 0)
        {
            game->max_cycles -= 5;
            game->left_cycles = game->max_cycles;
        }
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