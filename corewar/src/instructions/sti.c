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
#include "instructions.h"

void sti(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    byte type_param;

    type_param = (*memory)[cursor->position + 1];
    if (!is_type_param_valid(0x0b, type_param))
    {
        ++(cursor->position);
        return;
    }
    bypass_programs(programs, nb_programs);
}
