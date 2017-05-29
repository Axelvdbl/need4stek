/*
** pars_command1.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 14:15:44 2017 Alexandre Chamard-bois
** Last update Mon May 29 14:33:43 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include "command.h"

int pars_start(t_in *pars_in, t_out *pars_out)
{
  char **tab;
  char *str;

  write(1, "START_SIMULATION\n", 17);
  if (!(str = get_next_line(0)))
    return (-1);
  
}
