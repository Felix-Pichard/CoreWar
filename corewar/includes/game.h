/*
** my_strlen.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:16:07 2015 MARZI Nicolas
** Last update Tue Oct  6 10:01:30 2015 MARZI Nicolas
*/

#ifndef _GAME__H_
#define _GAME__H_

#include "op.h"
#include "memory.h"

typedef struct cursor_s
{
    int registers[REG_NUMBER + 1];
    int position;
    int cycles_left;
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
    byte        *memory[MEM_SIZE];
    program_t   **programs;
    cursor_t    **cursors;
} game_t;

typedef struct instruction_s
{
    byte        opcode;
    byte        nb_args;
    byte        cost;
    void        (*foo)(program_t *programs[], byte *memory[], cursor_t *cursor);
} instruction_t;

#endif