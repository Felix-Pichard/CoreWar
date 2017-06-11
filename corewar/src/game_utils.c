/*
** game_utils.c for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:24:33 2017 MARZI Nicolas
** Last update Sun Jun 11 10:50:05 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "game.h"

int nb_program_alive(program_t *programs, int nb)
{
    int i;
    int size;

    for (i = 0; i < nb; i++)
    {
        if (programs[i].alive != -1)
            size++;
    }
    return (size);
}