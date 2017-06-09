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

char *old_gfc(char *filename, int opponent_number)
{
    int fd;
    char *file_content;
    int i;
    //int check;
    int max_size;

    //check = 0;
    max_size = MEM_SIZE / opponent_number;
    file_content = malloc(max_size);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        my_error(7);
    my_put_nbr(read(fd, file_content, max_size));
    my_putstr(" octets red");
//    if (read(fd, file_content, max_size) == -1)
//        my_error(8);
    for (i = 0; i < max_size; ++i)
    {
//        if (file_content[i] == EOF)
//            check = 1;
    }
    /*if (check == 0)
        my_error(9);*/
    close(fd);
    return (file_content);
}

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
        file_content = malloc(header->prog_size*sizeof(byte));
        for (i = 0; i < header->prog_size; i++) {
            read(fd, &tmp_char, 1);
            file_content[i] = (byte) tmp_char;
        }
    }
    else
        my_error(12);
    return (file_content);
}   

header_t *get_header(char *file_content, int opponent_number)
{
    header_t *header;


    if ((header = malloc(sizeof(*header))) == NULL)
        my_error(5);
    my_putstr(file_content);
    my_putstr("\n");
    my_putstr("DEBUG 1\n");
    //int header_size = COMMENT_LENGTH + PROG_NAME_LENGTH + sizeof(int) * 2;
    my_putstr("DEBUG 2\n");
    /*if (my_bstrlen(file_content) < header_size)
        my_error(10);*/
    my_putstr("DEBUG 3\n");
    header->magic = my_getnbr(my_strnncpy(file_content, 0, sizeof(int)));
    my_strcpy(header->prog_name,my_strnncpy(file_content, sizeof(int), PROG_NAME_LENGTH));
    header->prog_size = my_getnbr(my_strnncpy(file_content, sizeof(int) + PROG_NAME_LENGTH + 1, sizeof(int)));
    my_put_nbr(header->prog_size);
    my_putstr(" size get \n");
//    if (header->magic != COREWAR_EXEC_MAGIC)
//        my_error(11);
    if (header->prog_size > MEM_SIZE * opponent_number)
        my_error(12);
    return (header);
}
