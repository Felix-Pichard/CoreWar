/*
** my_strlen.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:16:07 2015 MARZI Nicolas
** Last update Tue Oct  6 10:01:30 2015 MARZI Nicolas
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "header_parser.h"
#include "error.h"
#include "libmy.h"
#include "op.h"

byte *get_file_content(char *filename, header_t *header, int opponent_number)
{
    int fd;
    byte *file_content;
    unsigned char tmp_char;
    int max_size;
    int i;

    max_size = MEM_SIZE / opponent_number;
    fd = open(filename, O_RDONLY);
    header->magic = 0;
    if (fd == -1)
        my_error(7);
    for (i = 3; i >= 0; i--) {
        read(fd, &tmp_char, 1);
        header->magic += (int) tmp_char << i*8;
    }
    for (i = 0; i < PROG_NAME_LENGTH; i++) {
        read(fd, &tmp_char, 1);
        header->prog_name[i] = tmp_char;
    }
    for (i = 3; i >= 0; i--) {
        read(fd, &tmp_char, 1);
        header->prog_size += (int) tmp_char << i*8;
    }
    for (i = 0; i < COMMENT_LENGTH; i++) {
        read(fd, &tmp_char, 1);
        header->comment[i] = tmp_char;
    }
    if (header->prog_size < max_size)
    {
        file_content = safe_malloc(header->prog_size*sizeof(byte));
        for (i = 0; i < header->prog_size; i++) {
            read(fd, &tmp_char, 1);
            file_content[i] = (byte) tmp_char;
        }
    }
    else
        my_error(12);
    return (file_content);
}