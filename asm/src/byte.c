/*
** byte.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 07:49:14 2017 MARZI Nicolas
** Last update Thu Jun  8 07:53:12 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "libmy.h"
#include "byte.h"

void print_byte(byte b)
{
    int i;
    byte mask;

    mask = 1;
    for (i = 7; i >= 0; i--)
        my_put_nbr((b >> i) & mask);
}

byte *int_to_byte(int n, int size)
{
    byte *result;
    byte mask;
    int i;
    
    result = malloc(sizeof(byte) * size + 1);
    mask = 255;
    for (i = size; i > 0; i--)
    {
        result[size - i] = (byte) (n >> ((i - 1) * 8)) & mask;
    }
    return (result);
}
