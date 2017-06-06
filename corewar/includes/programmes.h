/*
** main.c for COREWAR in /media/maniarr/Workspace/etna/CoreWar/asm/src
**
** Made by MARZI Nicolas
** Login   <marzi_n@etna-alternance.net>
**
** Started on  Mon Jun  5 13:27:50 2017 MARZI Nicolas
** Last update Mon Jun  5 13:28:53 2017 MARZI Nicolas
*/

#ifndef _PROGRAMMES__H_
#define _PROGRAMMES__H_

#include "op.h"

typedef struct programmes_s
{
	char *prog_name;
#if REG_SIZE == 1	
	uint8_t r[REG_NUMBER];
#elif REG_SIZE == 2
	uint16_t r[REG_NUMBER];
#elif REG_SIZE == 8
	uint64_t r[REG_NULBER];
#else
	uint32_t r[REG_NUMBER];
	
} programmes_t;

#endif
