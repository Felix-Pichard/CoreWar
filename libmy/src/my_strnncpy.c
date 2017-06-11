/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Thu Jun  8 17:09:32 2017 MARZI Nicolas
*/

#include "libmy.h"

char *my_strnncpy(char *src, int i, int size)
 {
    char* str;
    int count;

    str = safe_malloc(sizeof(char) * size);
    for (count = 0; src[i] != '\0' && count < size; ++i, ++count)
        str[count] = src[i];
    return (str);
 }

byte *my_bstrnncpy(byte *src[], int i, int size)
 {
    byte *str;
    int count;

    str = safe_malloc(sizeof(byte) * size);
    for (count = 0; *src[i] != '\0' && count < size; ++i, ++count)
        str[count] = *src[i];
    return (str);
 }
