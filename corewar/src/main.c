/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include "libmy.h"
#include "parser.h"
#include "op.h"
#include "manager.h"
#include "memory.h"

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
        if (tmp_prog.header->prog_size > (MEM_SIZE / meta->nbr_prg))
            return (0);
        if (tmp_prog.prog_size < 0)
            start_address = calc_address(i * (MEM_SIZE / meta->nbr_prg));
        else
            start_address = calc_address(tmp_prog.header->address);
        if (!put_program(start_addr, tmp_prog))
            return (0);
        my_putstr(tmp_prog.prog_name);
        my_putchar('\n');
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_byte *mem;
    t_meta *programs;

    programs = parser(argc, argv);
    mem = init_mem();
    mem = init_mem();
    print_tab(meta);
    free(mem);
    return (0);
}