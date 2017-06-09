/*
** my_strlen.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:16:07 2015 MARZI Nicolas
** Last update Tue Oct  6 10:01:30 2015 MARZI Nicolas
*/

#include "game.h"

int check_ld_args(byte args_type)
{
    return (0);
}

void ld(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    byte first;
    byte second;
    byte args_type;

    args_type = *memory[cursor->position + 1];
    first = args_type >> 6;
    second = args_type >> 4;

    if (!((first == CODED_DIR || first == CODED_IND) && second == CODED_REG))
        return;
    if (first == CODED_DIR)
        return;
}
