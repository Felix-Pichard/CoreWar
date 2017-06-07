#include "../../libmy/libmy.h"

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
