/*
** assemble.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 13:50:39 2017 MARZI Nicolas
** Last update Sun Jun 11 18:13:24 2017 MARZI Nicolas
*/

#include <stdlib.h>
#include <unistd.h>

#include "assemble.h"
#include "parser.h"
#include "instruction.h"
#include "libmy.h"
#include "label.h"
#include "header.h"
#include "free.h"
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
    int file_handle;
    byte *content;
    instruction_t *tmp;

    content = safe_malloc(sizeof(byte) * script->header.prog_size);
    offset = 0;
    init_byte_buffer(content, script->header.prog_size);
    tmp = script->instruction;
    while (tmp != NULL)
    {
        for (i = 0; i < tmp->nb_args; i++)
            replace_label(script->label, &tmp->args[i], offset);
        offset += write_instruction(content, offset, tmp);
        tmp = tmp->next;
    }
    file_handle = xopen_trunc(script->file_name);
    write_header(file_handle, script->header);
    write(file_handle, content, script->header.prog_size);
    close(file_handle);
    free_script(script);
    free(content);
    return (1);
}