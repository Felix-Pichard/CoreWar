/*
** debug.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 07:43:44 2017 MARZI Nicolas
** Last update Thu Jun  8 08:34:29 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "libmy.h"
#include "op.h"
#include "byte.h"
#include "instruction.h"
#include "debug.h"
#include "param.h"

void print_header(header_t *header)
{
    my_putstr("Header :\n");
    my_putstr("\tMagic   : ");my_put_nbr(header->magic);my_putstr("\n");
    my_putstr("\tName    : ");my_putstr(header->prog_name);my_putstr("\n");
    my_putstr("\tComment : ");my_putstr(header->comment);my_putstr("\n");
    my_putstr("\tSize    : ");my_put_nbr(header->prog_size);my_putstr("\n");
}

void print_instruction(instruction_t *container)
{
    int i;

    if (container == NULL)
        return;
    my_putstr("Instruction : \n");
    my_putstr("\tOpCode    : ");my_put_nbr(container->opcode);my_putstr("\n");
    my_putstr("\tSize      : ");my_put_nbr(get_size(*container));my_putstr("\n");
    my_putstr("\tParams    : ");print_byte(get_param_byte(*container));my_putstr("\n");
    my_putstr("\tNb Args   : ");my_put_nbr(container->nb_args);my_putstr("\n");
    my_putstr("\tArguments : ");my_putstr("\n");
    for (i = 0; i < container->nb_args; i++)
    {
        my_putstr("\t\t - ");my_put_nbr(container->args[i].type);my_putstr(" ");
        if (container->args[i].label != NULL)
            my_putstr(container->args[i].label);
        else
            my_put_nbr(container->args[i].value);
        my_putstr("\n");
    }
    if (container->next != NULL)
        print_instruction(container->next);
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

void print_label(label_t *container)
{
    if (container == NULL)
        return;

    my_putstr("Label : \n");
    my_putstr("\tname     : ");my_putstr(container->name);my_putstr("\n");
    my_putstr("\tposition : ");my_put_nbr(container->position);my_putstr("\n");

    if (container->next != NULL)
        print_label(container->next);
}

void print_line(int number)
{
    my_putstr(" at line ");
    my_put_nbr(number);
    my_putstr("\n");
}

void print_param_possibilities(byte type)
{
    int i;
    int print;

    print = 0;
    for (i = 1; i < 4; i++)
    {
        if (!(type & i))
            continue;
        if (print > 0)
            my_putstr(" | ");
        my_putstr(get_type_param(i));
        print++;
    }
}