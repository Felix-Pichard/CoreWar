/*
** label.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Wed Jun  7 08:51:04 2017 MARZI Nicolas
** Last update Sun Jun 11 13:34:07 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "parser.h"
#include "label.h"
#include "libmy.h"
#include "assemble.h"
#include "instruction.h"
#include "free.h"

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
    return (1);
}

void add_label(script_t *script, label_t item)
{
    label_t *tmp;

    tmp = script->label;
    if (script->label == NULL)
    {
        script->label = safe_malloc(sizeof(label_t));
        *script->label = item;
        script->label->next = NULL;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = safe_malloc(sizeof(label_t));
    *tmp->next = item;
}

int is_char_label(char c)
{
    int i;

    for (i = 0; i < my_strlen(LABEL_CHARS); i++)
    {
        if (c == LABEL_CHARS[i])
            return (1);
    }
    return (0);
}

int is_label(char *line)
{
    int cursor;

    for (cursor = 0; *(line + cursor) != '\0'; cursor++)
    {
        if (line[cursor] == LABEL_CHAR && cursor > 0)
            return (1);
        else if (is_char_label(line[cursor]) == 0)
            return (0);
    }
    return (0);
}

int set_label(char *line, script_t *script)
{
    char **labels;
    label_t item;

    labels = split_n_str(line, ':', 1);
    if (array_len(labels) >= 1)
    {
        item.name = duplicate_str(labels[0]);
        item.position = get_rec_size(script->instruction);
        item.next = NULL;
        add_label(script, item);
        if (array_len(labels) >= 2)
        {
            if (is_instruction(labels[1]))
                return (set_instruction(labels[1], script));
        }
        else
            return (1);
    }
    else
        my_putstr("Label is not valid");
    free(labels);
    return (0);
}