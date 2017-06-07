/*
** header.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 18:06:41 2017 MARZI Nicolas
** Last update Wed Jun  7 18:06:41 2017 MARZI Nicolas
*/

#include <fcntl.h>
#include <unistd.h>

#include "header.h"
#include "instruction.h"

void write_header(int file_handle, header_t header)
{
    byte *tmp;
    int i;

    tmp = int_to_byte(header.magic, 4);
    for (i = 0; i < 4; i++)
         write(file_handle, &tmp[i], 1);

    write(file_handle, header.prog_name, PROG_NAME_LENGTH);

    tmp = int_to_byte(header.prog_size, 1);
    for (i = 0; i < 4; i++)
         write(file_handle, &tmp[i], 1); 

    write(file_handle, header.comment, COMMENT_LENGTH);   
}