/*
** my_strlen.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:16:07 2015 MARZI Nicolas
** Last update Tue Oct  6 10:01:30 2015 MARZI Nicolas
*/

#ifndef _INSTRUCTIONS__H_
#define _INSTRUCTIONS__H_

#include "game.h"

void instruction(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);

void live(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void ld(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void lld(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void st(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void add(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void sub(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void mul(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void i_div(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void mod(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void i_and(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void i_or(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void i_xor(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void zjmp(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void ldi(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void lldi(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void sti(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void aff(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void i_fork(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);
void lfork(program_t *programs[], byte *memory[], cursor_t *cursor, int nb_programs);

int is_type_param_valid(byte opcode, byte type_params);
void bypass_programs(program_t *program[], int nb_programs);
int read_byte_to_int(byte *memory[], int position, int size);
int get_size_param(byte type_param, int i);
int get_param_value(byte *memory[], cursor_t *cursor, int i_param);
int get_param_value_process(byte *memory[], cursor_t *cursor, int i_param);
int get_param_long_value_process(byte *memory[], cursor_t *cursor, int i_param);
#endif