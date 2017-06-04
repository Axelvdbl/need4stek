/*
** pars_command1.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 14:15:44 2017 Alexandre Chamard-bois
** Last update Sun Jun  4 08:51:17 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "command.h"

int	lidar(float lid[32])
{
  int	ret;
  char	*str;

  dprintf(2, "get_info_lidar\n");
  write(1, "GET_INFO_LIDAR\n", 15);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code2(str, lid);
  free(str);
  return (ret);
}

int	get_speed(float *get)
{
  int	ret;
  char	*str;

  dprintf(2, "get_current_speed\n");
  write(1, "GET_CURRENT_SPEED\n", 18);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code3(str, get);
  free(str);
  return (ret);
}

int	get_wheels(float *get)
{
  int	ret;
  char	*str;

  dprintf(2, "get_current_wheels\n");
  write(1, "GET_CURRENT_WHEELS\n", 19);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code3(str, get);
  free(str);
  return (ret);
}

int	cycle_wait(int nb)
{
  int	ret;
  char	*str;

  dprintf(2, "cycle_wait:%d\n", nb);
  fflush(stdout);
  printf("CYCLE_WAIT:%d\n", nb);
  fflush(stdout);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code1(str);
  free(str);
  return (ret);
}
