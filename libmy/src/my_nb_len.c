/*
** my_nb_len.c for MYLIB in /home/marzi_n/Piscine/C/Libmy/marzi_n/libmy_01
** 
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
** 
** Started on  Fri Oct  2 18:32:47 2015 MARZI Nicolas
** Last update Wed Oct  7 18:32:35 2015 MARZI Nicolas
*/

int     my_nb_len(int n)
{
  int   length;
  length = 0;

  if (n < 0)
    {
      n = n * -1;
      length++;
    }

  while (n != 0)
  {
    n = n / 10;
    length++;
  }

  return (length);
}
