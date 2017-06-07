/*
** label.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 08:51:04 2017 MARZI Nicolas
** Last update Wed Jun  7 08:51:04 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "parser.h"
#include "label.h"
#include "libmy.h"


label_t *get_label(label_t *container, char *name)
{
    label_t *tmp;

    tmp = container;

    while (tmp != NULL)
    {
        if (my_strcmp(name, container->name) == 0)
            return (container);
        tmp = tmp->next;
    }
    return (NULL);
}

int get_value_label(label_t *label, int cursor)
{
    my_putstr("Offset: ");my_put_nbr(cursor);my_putstr("\n");
    my_putstr("Positi: ");my_put_nbr(label->position);my_putstr("\n");
    if (label->position > cursor)
        return (label->position);
    return (0x0000 - (cursor - label->position));
}

int replace_label(label_t *labels, param_t *param, int offset)
{
    label_t        *label;
    
    label = NULL;
    if (param->label == NULL)
        return (offset);
    label = get_label(labels, param->label);
    if (label == NULL)
        return (0);
    param->value = get_value_label(label, offset);
    my_putstr(param->label);
    my_put_nbr(get_value_label(label, offset));
    my_putstr("\n");
    return (1);
}

void add_label(script_t *script, label_t item)
{
    label_t *tmp;

    tmp = script->label;
    if (script->label == NULL)
    {
        script->label = malloc(sizeof(label_t));
        *script->label = item;
        script->label->next = NULL;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(label_t));
    *tmp->next = item;
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