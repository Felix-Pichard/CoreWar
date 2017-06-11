/*
** header.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 18:06:41 2017 MARZI Nicolas
** Last update Thu Jun  8 07:29:33 2017 MARZI Nicolas
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"
#include "instruction.h"
#include "libmy.h"
#include "free.h"

void write_header(int file_handle, header_t header)
{
    byte *tmp_byte;

    tmp_byte = int_to_byte(header.magic, 4);
    write(file_handle, tmp_byte, 4);
    free(tmp_byte);
    write(file_handle, header.prog_name, PROG_NAME_LENGTH);
    tmp_byte = int_to_byte(header.prog_size, 4);
    write(file_handle, tmp_byte, 4);
    free(tmp_byte);
    write(file_handle, header.comment, COMMENT_LENGTH);   
}

char *get_filename(char *file)
{
    int i;
    int size;
    char *result;
    char extension[4] = ".cor";
    char **name;
    
    name = split_str(file, '.');
    size = my_strlen(name[0]);
    result = safe_malloc(sizeof(char) * size);
    for (i = 0; i < size + 4; i++)
    {
        if (i >= size)
            result[i] = extension[i - size];
        else
            result[i] = name[0][i];
    }
    free_array(name);
    return (result);
}
