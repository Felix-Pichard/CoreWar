/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include "../header.h"


void my_error(char* error_message)
{
    my_putstr("Error: ");
    my_putstr(error_message);
    my_putstr("usage: corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address ] prog_name] ...\n");
    exit(0);
}

void check_dump(char** argv, int* i, int argc, int* cycle)
{
    if (*i + 1 < argc && *cycle == -1  && my_getnbr(argv[*i+1]) >= 0 && argv[*i+1][strspn(argv[*i+1], "0123456789")] == 0){
        *i = *i + 1;
         *cycle = my_getnbr(argv[*i]);
    }
    else
        my_error("Wrong cycle format\n");
}

int check_prog_n(char** argv, int* i, int argc)
{
    if (*i + 1 < argc && argv[*i+1][strspn(argv[*i+1], "0123456789")] == 0 && my_strcmp(argv[*i+1], "-a") != 0)
        *i = *i + 1;
    else
        my_error("Wrong number format\n");

    return my_getnbr(argv[*i]);
}

int check_prog_addr(char** argv, int* i, int argc)
{
    if (*i + 1 < argc && argv[*i+1][strspn(argv[*i+1], "0123456789")] == 0 && my_strcmp(argv[*i+1], "-n") != 0)
        *i = *i + 1;
    else
        my_error("Wrong address format\n");
    return my_getnbr(argv[*i]);
}

void print_tab(s_program programs[4])
{
    for (int i = 0; i < 4; ++i)
    {
        if (programs[i].prog_name != NULL)
        {
            my_putstr(programs[i].prog_name);
            my_putchar('\n');
            my_put_nbr(programs[i].address);
            my_putchar('\n');
            my_put_nbr(programs[i].number);
            my_putchar('\n');
            my_putchar('\n');
        }
    }
}

int main(int argc, char** argv)
{
    s_program programs[4];

    int count = 0;
    int cycle = -1;
    for (int i = 1; i < argc ; ++i)
    {
        if (my_strcmp(argv[i], "-dump") == 0)
            check_dump(argv, &i, argc, &cycle);
        else if (my_strcmp(argv[i], "-n") == 0)
            programs[count].number = check_prog_n(argv, &i, argc);
        else if (my_strcmp(argv[i], "-a") == 0)
            programs[count].address = check_prog_addr(argv, &i, argc);
        else
        {
            programs[count].prog_name = argv[i];
            if (count >= 4)
                my_error("Only 4 champions allowed\n");
            ++count;
        }
    }
    for (; count < 4; ++count)
        programs[count].prog_name = NULL;

    print_tab(programs);
    return (0);
}
