/*
** game.c for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:18:31 2017 MARZI Nicolas
** Last update Fri Jun  9 09:25:12 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "libmy.h"
#include "game.h"
#include "op.h"
#include "instructions.h"

void init_game(game_t *game)
{
    game->max_cycles = CYCLE_TO_DIE;
    game->left_cycles = 10;
    // game->nb_player = nb_program(game->programs);
    game->dump_cycles = -1;
}

void launch_game(game_t *game)
{
    int i;
    cursor_t *current_cursor;
    
    // nb_player_alive
    while (nb_program_alive(game->programs) /* tmp */ && game->max_cycles > 0 && game->dump_cycles != 0)
    {
        for (i = 0; i < game->nb_player; i++)
        {
            if (game->programs[i].alive != -1)
                instruction(game->programs, game->memory, game->cursors[i], game->nb_player);
        }
        if (game->dump_cycles != -1)
            game->dump_cycles--;
        if (game->left_cycles == 0)
        {
            for (i = 0; i < game->nb_player; i++)
            {
                if (game->programs[i].alive <= 0)
                    game->programs[i].alive = -1;
                else
                    game->programs[i].alive = 0;
            }
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

    for (; game->programs != NULL;)
    {
        clean = game->programs;
        // free(clean->name);
        free(clean);
        game->programs++;
    }
    // free(game->programs);
}