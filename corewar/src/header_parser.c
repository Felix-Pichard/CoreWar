/*
** my_strlen.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:16:07 2015 MARZI Nicolas
** Last update Tue Oct  6 10:01:30 2015 MARZI Nicolas
*/

#include "header_parser.h"
#include "error.h"
#include "libmy.h"

char *get_file_content(char *filename, int max_size)
{
    File fd;
    char *file_content;
    int i;
    int check;

    check = 0;
    file_content = malloc(max_size);
    fd = open(filename);
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
    header_t header;
    int header_size = COMMENT_LENGTH + PROG_NAME_LENGTH + sizeof(int) * 2;
    if (my_bstrlen(file_content) < header_size)
        my_error(10);
    header.magic = my_strnncpy(file_content, 0, sizeof(int));
    header.prog_name = my_strnncpy(file_content, sizeof(int), PROG_NAME_LENGTH);
    header.prog_size = my_strnncpy(file_content, sizeof(int) + PROG_NAME_LENGTH + 1, sizeof(int));
    if (my_getnbr(header.magic) != COREWAR_EXEC_MAGIC)
        my_error(11);
    if (header.prog_size > MEM_SIZE * opponent_number)
        my_error(12);
    return (&header);
}