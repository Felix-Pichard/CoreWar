/*
** my_strlen.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:16:07 2015 MARZI Nicolas
** Last update Tue Oct  6 10:01:30 2015 MARZI Nicolas
*/

#ifndef __HEADER__PARSER__H_
#define __HEADER__PARSER__H_

#include "op.h"

char *get_file_content(char *filename);
header_t *get_header(char *file_content);

#endif