/*
** game_utils.c for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:24:33 2017 MARZI Nicolas
** Last update Fri Jun  9 09:51:45 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "game.h"

// int nb_program(program_t *program)
// {
//     int size;
    
//     for (;program != NULL; program++)
//     {
//         if (size > 4)
//             exit(0);
//         size++;
//     }
// }

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