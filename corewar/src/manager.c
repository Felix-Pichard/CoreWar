/*
** manager.h for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Tue Jun  6 16:28:53 2017 VIALLON Louis
*/

#include "parser.h"
#include "op.h"
#include "manager.h"

int calc_address(int initial_address)
{
    if (initial_address < 0)
        initial_address = MEM_SIZE - ((-initial_address) % MEM_SIZE);
    else
        initial_address = initial_address % MEM_SIZE;
    return (initial_address);
}

int try_put_programs(t_meta *meta)
{
    int i;
    int start_address;
    t_program tmp_prog;

    for (i = 0; i < meta->nbr_prg; ++i) {
        tmp_prog = meta->programs[i];
        if (tmp_prog.header.prog_size > (MEM_SIZE / meta->nbr_prg))
            return (0);
        if (tmp_prog.header.prog_size < 0)
            start_address = calc_address(i * (MEM_SIZE / meta->nbr_prg));
        else
            start_address = calc_address(tmp_prog.address);
        if (!put_program(&tmp_prog, start_address))
            return (1);
        my_put_nbr(tmp_prog.header.prog_size);
        my_putchar('\n');
        my_putstr(tmp_prog.file_name);
        my_putchar('\n');
        my_put_nbr(start_address);
        my_putchar('\n');
        my_putchar('\n');
    }
    return (0);
}

int put_program(t_program *program, int start_address)
{
    program->address = start_address;
    return (0);
}
