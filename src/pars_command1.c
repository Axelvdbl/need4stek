/*
** pars_command1.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 14:15:44 2017 Alexandre Chamard-bois
** Last update Sun Jun  4 08:50:44 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "command.h"

int	start()
{
  int	ret;
  char	*str;

  dprintf(2, "start_simulation\n");
  write(1, "START_SIMULATION\n", 17);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code1(str);
  free(str);
  return (ret);
}

int	stop()
{
  int	ret;
  char	*str;

  dprintf(2, "stop_simulation\n");
  write(1, "STOP_SIMULATION\n", 16);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code1(str);
  free(str);
  return (ret);
}

int	forward(float nb)
{
  int	ret;
  char	*str;

  dprintf(2, "car_forward:%f\n", nb);
  printf("CAR_FORWARD:%f\n", nb);
  fflush(stdout);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code1(str);
  free(str);
  return (ret);
}

int	backwards(float nb)
{
  int	ret;
  char	*str;

  dprintf(2, "car_backwards:%f\n", nb);
  printf("CAR_BACKWARDS:%f\n", nb);
  fflush(stdout);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code1(str);
  free(str);
  return (ret);
}

int	wheels_dir(float nb)
{
  int	ret;
  char	*str;

  dprintf(2, "wheels_dir:%f\n", nb);
  printf("WHEELS_DIR:%f\n", nb);
  fflush(stdout);
  if (!(str = get_next_line(0)))
    return (-1);
  ret = recup_code1(str);
  free(str);
  return (ret);
}
