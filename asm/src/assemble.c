/*
** assemble.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 13:50:39 2017 MARZI Nicolas
** Last update Wed Jun  7 13:50:39 2017 MARZI Nicolas
*/

#include <stdlib.h>
#include <unistd.h>

#include "assemble.h"
#include "parser.h"
#include "instruction.h"
#include "libmy.h"
#include "label.h"
#include "header.h"
#include "file.h"

void init_byte_buffer(byte *buffer, int size)
{
    int i;

    for (i = 0; i < size; i++)
        buffer[i] = 0;
}

int write_buffer(byte *buffer, byte *content, int offset, int size)
{
    int i;

    for (i = 0; i < size; i++)
        buffer[i + offset] = content[i];
    return (size);
}

int assemble(script_t *script)
{
    int i;
    int offset;
    byte content[script->header.prog_size];
    instruction_t *tmp;

    offset = 0;
    init_byte_buffer(content, script->header.prog_size);
    tmp = script->instruction;

    while (tmp != NULL)
    {
        my_putstr("Instruction: ");my_put_nbr(tmp->opcode);my_putstr("\n");
        for (i = 0; i < tmp->nb_args; i++)
            replace_label(script->label, &tmp->args[i], offset);
        offset += write_instruction(content, offset, tmp);
        tmp = tmp->next;
        my_putstr("\n");
    }
    for (int j = 0; j < offset; j++)
    {
        put_hex(content[j]);
    }
    int file_handle = xopen_trunc("test.cor");
    write_header(file_handle, script->header);
    for (i = 0; i < offset; i++)
    {
        write(file_handle, &content[i], 1);
    }
    close(file_handle);
    return (1);
}