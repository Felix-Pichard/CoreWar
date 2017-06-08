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
        {11, 3, 25, &sti},
        {12, 0, 1, &nop}
    };

void instruction(program_t *programs[], byte *memory[], cursor_t *cursor)
{
    if (*memory[cursor->position] > 11)
        instructions[11].foo(programs, memory, cursor);
    else
        instructions[*memory[cursor->position]].foo(programs, memory, cursor);
}
