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

void i_fork(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    cursor->position = (cursor->position + 1) % MEM_SIZE;
    bypass_programs(programs, nb_programs);
}