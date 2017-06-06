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

void push(char **container, char *item)
{
    container[array_len(container)] = item;

    if (is_comment(item))
    {
        my_putstr("comment    : ");my_putstr(item);my_putstr("\n");
    }
    else if (is_command(item))
        set_command(item);
    else if (is_label(item))
        set_label(item);
    else if (is_instruction(item))
        my_putstr("instruction: ");
    else if (is_null(item))
        my_putstr("null       \n");
    else
        my_putstr("error      : ");
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
    char *buffer_lines[128];
    int cursor;
    cursor = 0;

    init_buffer(buffer, 512);
    file_handle = xopen_read(filename);
    if (file_handle == -1)
        return;
    while (read(file_handle, &data, 1))
    {
        if (data == '\n')
        {
            push(buffer_lines, get_string(buffer));
            init_buffer(buffer, 512);
            cursor = 0;
        }
        else
        {
            buffer[cursor] = data;
            cursor++;
        }
    }
    push(buffer_lines, get_string(buffer));
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
