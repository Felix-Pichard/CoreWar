/*
** game_utils.c for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:24:33 2017 MARZI Nicolas
** Last update Thu Jun  8 18:16:01 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "game.h"

int nb_program_alive(program_t *programs)
{
    int size;

    for (;programs != NULL; programs++)
    {
        if (programs->alive)
            size++;
    }
    return (size);
}