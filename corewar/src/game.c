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
    game->left_cycles = 100;
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

void launch_game(game_t *game, int interactive_mode)
{
    int i;
    
    while (nb_program_alive(game->programs, game->nb_player) > 0 /*todo replace to 1 */ && game->max_cycles > 0 && game->dump_cycles != 0)
    {
        if (interactive_mode)
            get_command(&(game->memory));
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
                if (game->programs[i].alive <= 0)
                    game->programs[i].alive = -1;
                else
                    game->programs[i].alive = 0;
            }
            game->max_cycles -= CYCLE_DELTA;
            game->left_cycles = game->max_cycles;
        }
        game->left_cycles--;
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

void get_command(byte *memory[])
{
    char *command;
    char *num;
    static int counter;
    int i;
    int j;

    j = 0;
    num = safe_malloc(10);
    if (counter == 0)
    {
        my_putstr("\033c");
        dump(*memory);
        my_putstr("\n$/  ");
        command = readline();
        if (my_strcmp(command, "help") == 0)
            my_putstr("You can type: md x, where x is the number of cycles left before a memory dump.\n");
        if (command[0] == 'm' && command[1] == 'd')
        {
            for (i = 2; command[i] && command[i] > 47 && command[i] < 58; ++i)
                num[j++] = command[i];
            counter = my_getnbr(command);
        }
    }
    --i;
}
