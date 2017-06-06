/*
** parser.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Tue Jun  6 08:47:49 2017 MARZI Nicolas
** Last update Tue Jun  6 08:47:49 2017 MARZI Nicolas
*/

#include "op.h"

#ifndef __PARSER_H__
#define __PARSER_H__

typedef unsigned char byte;

typedef struct param_value_s
{
    char    *label;
    int     value;
} param_value_t;

typedef struct instruction_s
{
    byte opcode;
    byte nb_arguments;
    byte type_arguments;
    param_value_t args[MAX_ARGS_NUMBER];
    struct instruction_t *next;
} instruction_t;

int is_label(char *line);
int is_command(char *line);
int is_comment(char *line);
int is_instruction(char *line);
int is_null(char *line);

int is_param_register(char *line);
int is_param_dir(char *line);
int is_param_indir(char *line);

char *get_string(char *buffer);
void init_buffer(char *buffer, int size);
void escape_str(char *string);

void set_command(char *line);
void set_label(char *line);


int array_len(char **array);

#endif