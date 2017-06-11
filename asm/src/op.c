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
     {0, 0, {0}, 0, 0, 0}
  };
