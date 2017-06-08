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

void instruction(program_t *programs[], byte *memory[], cursor_t *cursor);

void live(program_t *programs[], byte *memory[], cursor_t *cursor);
void ld(program_t *programs[], byte *memory[], cursor_t *cursor);
void st(program_t *programs[], byte *memory[], cursor_t *cursor);
void add(program_t *programs[], byte *memory[], cursor_t *cursor);
void sub(program_t *programs[], byte *memory[], cursor_t *cursor);
void i_and(program_t *programs[], byte *memory[], cursor_t *cursor);
void i_or(program_t *programs[], byte *memory[], cursor_t *cursor);
void i_xor(program_t *programs[], byte *memory[], cursor_t *cursor);
void zjmp(program_t *programs[], byte *memory[], cursor_t *cursor);
void ldi(program_t *programs[], byte *memory[], cursor_t *cursor);
void sti(program_t *programs[], byte *memory[], cursor_t *cursor);
void nop(program_t *programs[], byte *memory[], cursor_t *cursor);

#endif