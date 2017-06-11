/*
** free.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Thu Jun  8 07:26:43 2017 MARZI Nicolas
** Last update Sun Jun 11 18:12:52 2017 MARZI Nicolas
*/

#include <stdlib.h>

#include "free.h"
#include "parser.h"

void free_array(char **array)
{
    int i;

    for (i = array_len(array) - 1; i > 0;i--)
        free(array[i]);
    free(array);
}

void free_instruction(instruction_t *instruction)
{
    instruction_t *tmp;
 
    while (instruction != NULL)
    {
        tmp = instruction;
        instruction = tmp->next;
        free(tmp);
    }
}

void free_label(label_t *label)
{
    label_t *tmp;
 
    while (label != NULL)
    {
        tmp = label;
        label = tmp->next;
        free(tmp);
    }
}

void free_script(script_t *script)
{
    free_instruction(script->instruction);
    free_label(script->label);
    free(script->file_name);
}

