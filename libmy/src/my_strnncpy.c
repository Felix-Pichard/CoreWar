/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#include <stdlib.h>

char *my_strnncpy(char *src, int i, int size)
 {
    char* str;
    int count;

    if((str = malloc(sizeof(char) * size)) == NULL)
        my_error(5);
    for (count = 0; src[i] != '\0' && count < size; ++i, ++count)
        str[count] = src[i];

    return (str);
 }
