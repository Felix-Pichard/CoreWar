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

char *get_file_content(char *filename, int opponent_number)
{
    int fd;
    char *file_content;
    int i;
    int check;
    int max_size;

    check = 0;
    max_size = MEM_SIZE / opponent_number;
    file_content = malloc(max_size);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        my_error(7);
    if (read(fd, file_content, max_size) == -1)
        my_error(8);
    for (i = 0; i < max_size; ++i)
    {
        if (file_content[i] == EOF)
            check = 1;
    }
    if (check == 0)
        my_error(9);
    return (file_content);
}

header_t *get_header(char *file_content, int opponent_number)
{
    header_t *header;

    if ((header = malloc(sizeof(*header))) == NULL)
        my_error(5);
    int header_size = COMMENT_LENGTH + PROG_NAME_LENGTH + sizeof(int) * 2;
    if (my_bstrlen(file_content) < header_size)
        my_error(10);
    header->magic = my_getnbr(my_strnncpy(file_content, 0, sizeof(int)));
    my_strcpy(header->prog_name,my_strnncpy(file_content, sizeof(int), PROG_NAME_LENGTH));
    header->prog_size = my_getnbr(my_strnncpy(file_content, sizeof(int) + PROG_NAME_LENGTH + 1, sizeof(int)));
    if (header->magic != COREWAR_EXEC_MAGIC)
        my_error(11);
    if (header->prog_size > MEM_SIZE * opponent_number)
        my_error(12);
    return (header);
}