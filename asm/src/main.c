/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Thu Jun  8 08:33:28 2017 MARZI Nicolas
*/

#include <stdlib.h>
#include <unistd.h>

#include "libmy.h"
#include "file.h"
#include "op.h"
#include "parser.h"
#include "label.h"
#include "instruction.h"
#include "command.h"
#include "assemble.h"
#include "header.h"
#include "free.h"
#include "debug.h"

int push(char *item, script_t *script)
{
    if (is_comment(item))       
        return (1);
    else if (is_command(item))
        return (set_command(item, script));
    else if (is_label(item))
        return (set_label(item, script));
    else if (is_instruction(item))
        return (set_instruction(item, script));
    else if (is_null(item))
        return (1);
    else
        my_putstr("Unknow instruction");
    return (0);
}

void assemble_file(char *filename)
{
    int file_handle;
    char data;
    char buffer[512];
    int cursor;
    int response;
    int line;

    script_t warrior = {NULL, NULL, {COREWAR_EXEC_MAGIC, "", 0, ""}, get_filename(filename)};
    cursor = 0;
    response = 1;
    line = 1;
    init_buffer(buffer, 512);
    file_handle = xopen_read(filename);
    if (file_handle == -1)
        return;
    while (read(file_handle, &data, 1) && response == 1)
    {
        if (data == '\n')
        {
            response = push(get_string(buffer), &warrior);
            init_buffer(buffer, 512);
            if (response == 0)
                print_line(line);
            cursor = 0;
            line++;
        }
        else
            buffer[cursor++] = data;
    }
    close(file_handle);
    if (!push(get_string(buffer), &warrior))
        print_line(line);
    else
    {
        warrior.header.prog_size = get_rec_size(warrior.instruction);
        assemble(&warrior);
    }
    free_script(warrior);
}

int main(int argv, char **args)
{
    if (argv < 1)
    {
        my_putstr("asm file_name[.s] ...");
        return (-1);
    }
    for (int i = 1; i < argv; i++)
    {
        if (!file_exists(args[i]))
        {
            my_putstr("File doesn't exist or is directory: ");
            my_putstr(args[i]);
            my_putstr("\n");
            return (-1);
        }
        assemble_file(args[i]);
    }
    return (0);
}
