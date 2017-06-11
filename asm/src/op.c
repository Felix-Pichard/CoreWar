/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Tue Mar 22 16:44:20 2011 Astek
*/

/*
** Ne pas passer ce fichier dans la moulinette de Norme.
*/

#include "op.h"

op_t    op_tab[] =
  {
    {"live", 1, {CODED_DIR}, 1, 10, "alive"},
    {"ld", 2, {CODED_DIR | CODED_IND, CODED_REG}, 2, 5, "load"},
    {"st", 2, {CODED_REG, CODED_IND | CODED_REG}, 3, 5, "store"},
    {"add", 3, {CODED_REG, CODED_REG, CODED_REG}, 4, 10, "addition"},
    {"sub", 3, {CODED_REG, CODED_REG, CODED_REG}, 5, 10, "soustraction"},
    {"and", 3, {CODED_REG | CODED_DIR | CODED_IND, CODED_REG | CODED_IND | CODED_DIR, CODED_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {CODED_REG | CODED_IND | CODED_DIR, CODED_REG | CODED_IND | CODED_DIR, CODED_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {CODED_REG | CODED_IND | CODED_DIR, CODED_REG | CODED_IND | CODED_DIR, CODED_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {CODED_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {CODED_REG | CODED_DIR | CODED_IND, CODED_DIR | CODED_REG, CODED_REG}, 10, 25,
     "load index"},
    {"sti", 3, {CODED_REG, CODED_REG | CODED_DIR | CODED_IND, CODED_DIR | CODED_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {"mul", 3, {T_REG, T_REG, T_REG}, 17, 30, "multiplication"},
    {"div", 3, {T_REG, T_REG, T_REG}, 18, 60, "division"},
    {"mod", 3, {T_REG, T_REG, T_REG}, 19, 150, "modulus"},
    {0, 0, {0}, 0, 0, 0}
  };
