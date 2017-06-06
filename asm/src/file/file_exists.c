/*
** file_exist.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src/file
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 16:08:19 2017 MARZI Nicolas
** Last update Mon Jun  5 16:08:19 2017 MARZI Nicolas
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libmy.h"

int     file_exists(char *file_name)
{
    struct stat file_stat;
    return ((stat(file_name, &file_stat) < 0 || S_ISDIR(file_stat.st_mode) == 0) ? 1 : 0);
}