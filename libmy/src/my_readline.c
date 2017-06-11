/*
** game.c for COREWAR in /media/maniarr/Workspace1/etna/CoreWar/corewar/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 15:18:31 2017 MARZI Nicolas
** Last update Sun Jun 11 10:35:30 2017 MARZI Nicolas
*/

#include <unistd.h>
#include <stdlib.h>

char        *readline()
{
  ssize_t    ret;
  char        *buff;

  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}