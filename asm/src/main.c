/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
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

int push(char *item, script_t *script)
{
    if (is_comment(item))
    {
        my_putstr("comment    : ");my_putstr(item);my_putstr("\n");
        return (1);
    }
    else if (is_command(item))
        return (set_command(item, script));
    else if (is_label(item))
        return (set_label(item, script));
    else if (is_instruction(item))
        return (set_instruction(item, script));
    else if (is_null(item))
        return (1);
    return (0);
}

void print_array(char **container)
{
    while (*container != NULL)
    {
        my_putstr(*container);
        my_putstr("\n");
        container++;
    }
}

void print_file(char *filename)
{
    int file_handle;
    char data;
    char buffer[512];
    int cursor;
    int response;

    script_t warrior = {NULL, NULL, {COREWAR_EXEC_MAGIC, "", 0, ""}};
    cursor = 0;
    response = 1;
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
            cursor = 0;
        }
        else
            buffer[cursor++] = data;
    }
    push(get_string(buffer), &warrior);

    warrior.header.prog_size = get_rec_size(warrior.instruction);
    print_header(&warrior.header);
    print_label(warrior.label);
    print_instruction(warrior.instruction);
    assemble(&warrior);
    close(file_handle);
}

int main(int argv, char **args)
{
    // my_put_nbr(is_comment("# test tse"));my_putstr("\n");
    // my_put_nbr(is_comment("zea test tse"));my_putstr("\n");
    // my_put_nbr(is_command(".name zoidberg"));my_putstr("\n");
    // my_put_nbr(is_command(".nme zoidberg"));my_putstr("\n");
    // my_put_nbr(is_label("test2: zoidberg"));my_putstr("\n");
    // my_put_nbr(is_label("mabite zoidberg"));my_putstr("\n");
    // my_put_nbr(is_instruction("live zoidberg"));my_putstr("\n");
    // my_put_nbr(is_instruction("test zoidberg"));my_putstr("\n");
    // my_put_nbr(is_instruction("test zoidberg"));my_putstr("\n");

    
    // my_put_nbr(array_len(split_str("test", ',')));my_putstr("\n");
    // my_put_nbr(array_len(split_str("test,tze", ',')));my_putstr("\n");
    // my_put_nbr(array_len(split_str("zer,tes,zer", ',')));my_putstr("\n");
    // return (0);

    if (argv < 1)
    {
        my_putstr("asm file_name[.s] ...");
        return (-1);
    }

    for (int i = 1; i < argv; i++)
    {
        // TODO add filename without extension
        if (!file_exists(args[i]))
        {
            my_putstr("File doesn't exist or is directory: ");
            my_putstr(args[i]);
            my_putstr("\n");
            return (-1);
        }
        print_file(args[i]);
    }
    return (0);
}
