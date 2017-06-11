/*
** game.c for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:18:31 2017 MARZI Nicolas
** Last update Sun Jun 11 10:35:30 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "libmy.h"
#include "game.h"
#include "op.h"
#include "instructions.h"

void init_game(game_t *game)
{
    game->max_cycles = CYCLE_TO_DIE;
    game->left_cycles = game->max_cycles;
    game->dump_cycles = -1;
}

void print_register(int *tab)
{
    int i;

    for (i = 0; i <= REG_NUMBER; i++)
    {
        my_putstr("Reg ");my_put_nbr(i);
        my_putstr(": ");my_put_nbr(tab[i]);
        my_putstr("\n");
    }
}

void put_player(program_t *warrior)
{
    my_putstr("le joueur ");
    my_put_nbr(warrior->id);
    my_putstr("(");
    my_putstr(warrior->name);
    my_putstr(")");
}

void launch_game(game_t *game, int interactive_mode)
{
    int i;
    int counter;
    
    counter = 0;
    while (nb_program_alive(game->programs, game->nb_player) > 1 && game->max_cycles > 0 && game->dump_cycles != 0)
    {
        if (interactive_mode && counter <= 0)
            counter = get_command(game, counter);
        for (i = 0; i < game->nb_player; i++)
        {
            if (game->programs[i].alive != -1)
                instruction(&game->programs, &game->memory, &game->cursors[i], game->nb_player);
        }
        if (game->dump_cycles != -1)
            game->dump_cycles--;
        if (game->left_cycles == 0)
        {
            for (i = 0; i < game->nb_player; i++)
            {
                if (game->programs[i].alive == 0)
                {
                    game->programs[i].alive = -1;
                    put_player(&(game->programs[i]));
                    my_putstr(" est mort\n");
                }
                else if (game->programs[i].alive == 1)
                    game->programs[i].alive = 0;
            }
            game->max_cycles -= CYCLE_DELTA;
            game->left_cycles = game->max_cycles;
        }
        game->left_cycles--;
        counter--;
    }
}

void free_game(game_t *game)
{
    int i;

    for (i = 0; i < game->nb_player; i++)
    {
        free(&(game->programs[i]));
        free(&(game->cursors[i]));
    }
    free(game->memory);
}

int get_command(game_t *game, int counter)
{
    char *command;
    
    my_putstr("\033c");
    my_putstr("Max Cycles: ");
    my_put_nbr(game->max_cycles);
    my_putstr(" - Left Cycles: ");
    my_put_nbr(game->left_cycles);
    my_putstr("\n");
    dump(game->memory);
    my_putstr("\n$/  ");
    command = readline();
    if (my_strcmp(command, "help") == 0)
        my_putstr("You can type: x, where x is the number of cycles left before a memory dump.\n");
    counter = my_getnbr(command);
    return (counter);
}

void free_meta(t_meta* meta)
{
    int i;

    for (i = 0; i < meta->nbr_prg; i++)
        free(&(meta->programs[i]));
    free(meta);
}
