/*
** cycle.h for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Tue Jun  6 16:28:53 2017 VIALLON Louis
*/

int my_strspn (const char *s, const char *accept)
{
    const char *to_compare;
    int  count;
    int found;

    found = 0;
    count = 0;
    for (; *s != '\0'; ++s) {
         for (to_compare = accept; *to_compare != '\0'; ++to_compare) {
            if (*s == *to_compare)
                  found = 1;
         }
          if (found == 0)
            return count;
        ++count;
    }

      return count;
}