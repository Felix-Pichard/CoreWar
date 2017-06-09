/*
** game.h for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:32:49 2017 MARZI Nicolas
** Last update Fri Jun  9 10:22:46 2017 MARZI Nicolas
*/

#ifndef _GAME__H_
#define _GAME__H_

#include "op.h"
#include "memory.h"
#include "libmy.h"

typedef struct cursor_s
{
    int registers[REG_NUMBER + 1];
    int position;
    int cycles_left;
    int flag;
} cursor_t;

typedef struct program_s
{
    int id;
    int alive;
    char *name;
} program_t;

typedef struct game_s
{
    int         nb_player;
    int         max_cycles;
    int         left_cycles;
    int         dump_cycles;
    byte        *memory;
    program_t   *programs;
    cursor_t    *cursors;
} game_t;

typedef struct instruction_s
{
    byte        opcode;
    byte        nb_args;
    byte        cost;
    void        (*foo)(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
} instruction_t;

int nb_program_alive(program_t *programs, int nb);
// int nb_program(program_t *program);
void init_game(game_t *game);
void launch_game(game_t *game);
void free_game(game_t *game);

#endif