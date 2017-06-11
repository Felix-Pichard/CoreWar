/*
** parser.h for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/includes
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Tue Jun  6 08:47:49 2017 MARZI Nicolas
** Last update Sun Jun 11 13:40:40 2017 MARZI Nicolas
*/

#include "op.h"
#include "libmy.h"

#ifndef __PARSER_H__
#define __PARSER_H__

typedef struct param_s
{
    char    *label;
    int     value;
    byte    type;
} param_t;


typedef struct instruction_s instruction_t;
struct  instruction_s
{
    byte                    opcode;
    byte                    nb_args;
    param_t                 args[MAX_ARGS_NUMBER];
    instruction_t    *next;
};


typedef struct label_s label_t;
struct  label_s
{
    char     *name;
    byte     position;
    label_t  *next;
};

typedef struct  script_s
{
    label_t         *label;
    instruction_t   *instruction;
    header_t        header;
    char            *file_name;
}               script_t;

int is_command(char *line);
int is_comment(char *line);
int is_instruction(char *line);
int is_null(char *line);
int is_invisible_char(char c);

char *get_string(char *buffer);
void init_buffer(char *buffer, int size);
void escape_str(char *string);
int array_len(char **array);
char **split_str(char *line, char delimiter);

int is_nbr(char *line);

int set_command(char *line, script_t *script);
int set_label(char *line, script_t *script);
int set_instruction(char *line, script_t *script);

int set_params(instruction_t *instruction, char **lines, int size);
op_t get_op(char *name);
int find_occurence(char *line, char find);

void init_container_buffer(char **buffer, int size);
void init_buffer(char *buffer, int size);

#endif