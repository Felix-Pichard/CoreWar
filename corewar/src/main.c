/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include <libzvbi.h>
#include <malloc.h>
#include "libmy.h"
#include "op.h"
#include "cycle.h"

static t_cycle	*cycle_init()
{
    t_cycle	*cycle;

    if ((cycle = (t_cycle*)malloc(sizeof(t_cycle))) != NULL)
    {
        cycle->nbr = 1;
        cycle->live_calls = NBR_LIVE;
        cycle->die = CYCLE_TO_DIE;
    }
    return (cycle);
}

int launch_corewar()
{
    if (cycle_init())
        return (0);
    return (-1);
}

int main(int argc, char **argv)
{
    if (argc > 1 && argv != NULL)
        return (launch_corewar());
    else
        my_putstr("corewar: At least one argument required\n");
    return (-1);
}
