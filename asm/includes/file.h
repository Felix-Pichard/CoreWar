/*
** file.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src/file
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 16:08:50 2017 MARZI Nicolas
** Last update Mon Jun  5 16:08:50 2017 MARZI Nicolas
*/

#ifndef __FILE_H__
#define __FILE_H__

int         file_exists(char *file);
int		    xopen_read(char *file_name);
int         xopen_trunc(char *file_name);

#endif