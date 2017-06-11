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
#include "memory.h"

instruction_t instructions[] = 
    {
        {1, 1, 10, &live},
        {2, 2, 5, &ld},
        {3, 2, 5, &st},
        {4, 3, 10, &add},
        {5, 3, 10, &sub},
        {6, 3, 6, &i_and},
        {7, 3, 6, &i_or},
        {8, 3, 6, &i_xor},
        {9, 1, 20, &zjmp},
        {10, 3, 25, &ldi},
        {11, 3, 25, &sti}
    };

void instruction(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs)
{
    byte opcode;

    opcode = (*memory)[cursor->position];
    if (cursor->flag == 1 && cursor->cycles_left == 0)
    {
        if (opcode > 15 || opcode < 1)
            cursor->position = (cursor->position + 1) % MEM_SIZE;
        else
            instructions[opcode - 1].foo(programs, memory, cursor, nb_programs);
        cursor->flag = 0;
        return;
    }
    if (cursor->flag == 0 && cursor->cycles_left == 0)
    {
        cursor->flag = 1;
        cursor->cycles_left = instructions[opcode - 1].cost;
    }
    if (cursor->cycles_left > 0)
        --cursor->cycles_left;
}
