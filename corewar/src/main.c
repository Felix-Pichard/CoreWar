/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include "parser.c"


int main(int argc, char** argv)
{
    t_meta* mabite;
    mabite = parser(argc, argv);
    print_tab(mabite);
    return (0);
}
