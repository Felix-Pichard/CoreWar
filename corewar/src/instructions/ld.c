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

void ld(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    int i;
    byte type_param;
    byte nb_register;

    if (!is_type_param_valid(0x02, (*memory)[cursor->position + 1]))
        return;
    if (type_param >> 6 == CODED_DIR)
        nb_register = *memory[cursor->position + 1 + DIR_SIZE];
    else
        nb_register = *memory[cursor->position + 1 + IND_SIZE];

    if (nb_register > REG_NUMBER || nb_register < 1)
        return;
    
    if (type_param >> 6 == CODED_DIR)
    {
        for (i = 1; i <= DIR_SIZE; i++)
        {
            cursor->registers[nb_register] = *memory[cursor->position + 1 + i] << (DIR_SIZE - i) * 8;
        }
    }
}
