/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include "error.h"
#include "libmy.h"

void my_error(int i)
{
    char* errors[13];

    errors[0] = "Tout va bien\n";
    errors[1] = "Wrong cycle format\n";
    errors[2] = "Wrong number format\n";
    errors[3] = "Wrong address format\n";
    errors[4] = "Only 4 champions max allowed\n";
    errors[5] = "Can’t perform malloc\n";
    errors[6] = "Wrong number of argument\n";
    errors[7] = "Cannot open the file\n";
    errors[8] = "Cannot read the file\n";
    errors[9] = "Too much source code\n";
    errors[10] = "File is not a corewar executable\n";
    errors[11] = "File has not the correct magic const\n";
    errors[12] = "File has a too long source code\n";
    my_putstr("Error: ");
    my_putstr(errors[i]);
    my_putstr("usage: corewar [-dump nbr_cycle] [-i] [[-n prog_number] [-a load_address ] prog_name] ...\n");
    exit(i);
}

void check_dump(char** argv, int* i, int argc, int* cycle)
{
    if (*i + 1 < argc && *cycle == -1  && my_getnbr(argv[*i+1]) >= 0 && argv[*i+1][my_strspn(argv[*i+1], "0123456789")] == 0){
        *i = *i + 1;
         *cycle = my_getnbr(argv[*i]);
    }
    else
        my_error(1);
}

int check_prog_n(char** argv, int* i, int argc)
{
    if (*i + 1 < argc && argv[*i+1][my_strspn(argv[*i+1], "0123456789")] == 0 && my_strcmp(argv[*i+1], "-a") != 0)
        *i = *i + 1;
    else
        my_error(2);

    return my_getnbr(argv[*i]);
}

int check_prog_addr(char** argv, int* i, int argc)
{
    if (*i + 1 < argc && argv[*i+1][my_strspn(argv[*i+1], "0123456789")] == 0 && my_strcmp(argv[*i+1], "-n") != 0)
        *i = *i + 1;
    else
        my_error(3);
    return my_getnbr(argv[*i]);
}
