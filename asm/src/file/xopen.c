/*
** xopen.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src/file
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 14:19:43 2017 MARZI Nicolas
** Last update Sun Jun 11 12:42:16 2017 MARZI Nicolas
*/

#include <fcntl.h>

#include "libmy.h"

int     xopen_trunc(char *file_name)
{
  int file_handle;

  file_handle = open(file_name, O_TRUNC | O_WRONLY | O_CREAT);
  if (file_handle == -1)
    my_putstr("File Error !\n");
  return (file_handle);
}

int		  xopen_read(char *file_name)
{
  int file_handle;

  file_handle = open(file_name, O_RDONLY);
  if (file_handle == -1)
    my_putstr("File Error !\n");
  return (file_handle);
}