/*
** cycle.h for CoreWar in /home/louis/CoreWar/corewar/includes
**
** Made by VIALLON Louis
** Login   <viallo_l@etna-alternance.net>
**
** Started on  Tue Jun  6 16:27:50 2017 VIALLON Louis
** Last update Tue Jun  6 16:28:53 2017 VIALLON Louis
*/

#ifndef _MANAGER__H_
#define _MANAGER__H_

int calc_address(int initial_address);
int try_put_programs(t_meta *meta);
int put_program(t_program *program, int start_addr);

#endif
