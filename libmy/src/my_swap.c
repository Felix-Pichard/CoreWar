/*
** my_swap.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Thu Oct  1 19:12:42 2015 MARZI Nicolas
** Last update Thu Oct  1 19:13:19 2015 MARZI Nicolas
*/

void	my_swap(int *a, int *b)
{
  int swap;
  swap = *b;
  *b = *a;
  *a = swap;
}
