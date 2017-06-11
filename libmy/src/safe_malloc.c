/*
** safe_malloc.c for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Fri Jun  9 08:23:59 2017 MARZI Nicolas
*/

#include "libmy.h"

void* safe_malloc(size_t size) {
    void *allocated;
    
    allocated = malloc(size);
    if (allocated == NULL) {
        my_putstr("Unable to allocate memory\n");
        exit(-1);
    }
    return (allocated);
}
