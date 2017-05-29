/*
** pars_command1.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 14:15:44 2017 Alexandre Chamard-bois
** Last update Mon May 29 22:30:54 2017 Alexandre Chamard-bois
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "command.h"

int get_speed_max(t_out *pars_out)
{
  int ret;
  char *str;

  dprintf(2, "get_car_speed_max\n");
  write(1, "GET_CAR_SPEED_MAX\n", 18);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code3(str, pars_out);
  free(str);
  return (ret);
}

int get_speed_min(t_out *pars_out)
{
  int ret;
  char *str;

  dprintf(2, "get_car_speed_min\n");
  write(1, "GET_CAR_SPEED_MIN\n", 18);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code3(str, pars_out);
  free(str);
  return (ret);
}

int get_simtime(t_out *pars_out)
{
  int ret;
  char *str;

  dprintf(2, "get_info_simtime\n");
  write(1, "GET_INFO_SIMTIME\n", 17);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code4(str, pars_out);
  free(str);
  return (ret);
}
