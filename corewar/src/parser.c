#include "../parser.h"
#include "error.c"

void print_tab(t_meta* test)
{
    for (int i = 0; i < test->nbr_prg; ++i)
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

    for (int i = 1; i < argc ; ++i)
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
                my_error("Only 4 champions allowed\n");
            ++count;
        }
    }

}


void init_meta(t_meta *meta)
{
    meta->programs = malloc(sizeof(t_program) * meta->nbr_prg);

    for (int i = 0; i < meta->nbr_prg; ++i)
    {
        meta->programs[i].prog_name = "";
        meta->programs[i].number = 0;
        meta->programs[i].address = 0;
        meta->programs[i].cycle_of_instruction = 0;
        meta->programs[i].cycle_spent = 0;
    }
    my_putstr(meta->programs[0].prog_name);
}

void parser(int argc, char** argv)
{
    t_meta test;
    int count;

    count = 0;
    for (int i = 1; i < argc ; ++i)
    {
        if (my_strcmp(argv[i], "-dump") == 0 || my_strcmp(argv[i], "-n") == 0 || my_strcmp(argv[i], "-a") == 0)
            i = i + 1;
        else
        {
            if (count >= 4)
                my_error("Only 4 champions max allowed\n");
            ++count;
        }
    }
    test.nbr_prg = count;
    init_meta(&test);
    fill_struct(argc, argv, &test);
    print_tab(&test);
}
