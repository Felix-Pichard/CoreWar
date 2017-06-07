/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include "parser.h"
#include "error.h"

void print_tab(t_meta* test)
{
	int i;

    for (i = 0; i < test->nbr_prg; ++i)
    {
        if (test->programs[i].prog_name != NULL)
        {
            my_putstr(test->programs[i].prog_name);
            my_putchar('\n');
            my_put_nbr(test->programs[i].address);
            my_putchar('\n');
            my_put_nbr(test->programs[i].number);
            my_putchar('\n');
            my_putchar('\n');
        }
    }
}

void fill_struct(int argc, char** argv, t_meta *test)
{
    int count = 0;
    int cycle = -1;
	int i;

    for (i = 1; i < argc ; ++i)
    {
        if (my_strcmp(argv[i], "-dump") == 0)
            check_dump(argv, &i, argc, &cycle);
        else if (my_strcmp(argv[i], "-n") == 0)
            test->programs[count].number = check_prog_n(argv, &i, argc);
        else if (my_strcmp(argv[i], "-a") == 0)
            test->programs[count].address = check_prog_addr(argv, &i, argc);
        else
        {
            test->programs[count].prog_name = argv[i];
            if (count >= 4)
                my_error(4);
            ++count;
        }
    }

}


void init_meta(t_meta *meta)
{
	int i;

    if ((meta->programs = malloc(sizeof(t_program) * meta->nbr_prg)) == NULL)
		my_error(5);

    for (i = 0; i < meta->nbr_prg; ++i)
    {
        meta->programs[i].prog_name = "";
        meta->programs[i].number = 0;
        meta->programs[i].address = 0;
        meta->programs[i].cycle_of_instruction = 0;
        meta->programs[i].cycle_spent = 0;
    }
    my_putstr(meta->programs[0].prog_name);
}

t_meta* parser(int argc, char** argv)
{
    t_meta* prog_args;
    int count;
	int i;

    if ((prog_args = malloc(sizeof(t_meta))) == NULL)
		my_error(5);
    count = 0;
    for (i = 1; i < argc ; ++i)
    {
        if (my_strcmp(argv[i], "-dump") == 0 || my_strcmp(argv[i], "-n") == 0 || my_strcmp(argv[i], "-a") == 0)
            ++i;
        else
        {
            if (count >= 4)
                my_error(4);
            ++count;
        }
    }
    prog_args->nbr_prg = count;
    init_meta(prog_args);
    fill_struct(argc, argv, prog_args);
    
	return (prog_args);
}