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

void live(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    int warrior_id;

    warrior_id = read_byte_to_int(memory, cursor->position + 1, DIR_SIZE);
    if (warrior_id < nb_programs && programs[warrior_id]->alive != -1)
    {
        my_putstr("le joueur ");
        my_put_nbr(programs[warrior_id]->id);
        my_putstr("(");
        my_putstr(programs[warrior_id]->name);
        my_putstr(") est en vie\n");
        programs[warrior_id]->alive = 1;
    }
    cursor->position = (cursor->position + 1 + DIR_SIZE) % MEM_SIZE;
}
