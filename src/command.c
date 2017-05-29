/*
** command.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 11:44:03 2017 Alexandre Chamard-bois
** Last update Mon May 29 13:57:54 2017 Alexandre Chamard-bois
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libmy.h"
#include "command.h"

t_command g_command[] =
{
  {START, NULL, "START_SIMULATION"},
  {STOP, NULL, "STOP_SIMULATION"},
  {FORWARD, NULL, "CAR_FORWARD"},
  {BACKWARDS, NULL, "CAR_BACKWARDS"},
  {WHEELS_DIR, NULL, "WHEELS_DIR"},
  {LIDAR, NULL, "GET_INFO_LIDAR"},
  {GET_SPEED, NULL, "GET_CURRENT_SPEED"},
  {GET_WHEELS, NULL, "GET_CURRENT_WHEELS"},
  {WAIT, NULL, "CYCLE_WAIT"},
  {GET_SPEED_MAX, NULL, "GET_CAR_SPEED_MAX"},
  {GET_SPEED_MIN, NULL, "GET_CAR_SPEED_MIN"},
  {GET_SIMTIME, NULL, "GET_INFO_SMTIME"},
  {0, NULL, NULL},
};

int recup_code()
{
  int   nb;
  char  status[3][128];
  float lidar[32];
  char *str;

  if (!(str = get_next_line(0)))
    return (1);
  memset(status, 0, 256);
  if (sscanf(str, "%d:%[^:]:%[^:]:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:"
      "%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%f:%s",
      &nb, status[0], status[1], &lidar[0], &lidar[1], &lidar[2], &lidar[3],
      &lidar[4], &lidar[5], &lidar[6], &lidar[7], &lidar[8], &lidar[9],
      &lidar[10], &lidar[11], &lidar[12], &lidar[13], &lidar[14], &lidar[15],
      &lidar[16], &lidar[17], &lidar[18], &lidar[19], &lidar[20], &lidar[21],
      &lidar[22], &lidar[23], &lidar[24], &lidar[25], &lidar[26], &lidar[27],
      &lidar[28], &lidar[29], &lidar[30], &lidar[31], status[2]) != 36)
    return (1);
  printf("%d\n%s\n%s\n", nb, status[0], status[1]);
  free(str);
  return (nb);
}

int pars_cmd(const int cmd)
{
  t_in *pars_in;
  t_in *pars_out;

}

int main()
{
  int i;
  char *str;

  while ((str = get_next_line(0)))
  {
    i = 0;
    while (g_command[i].tmp && strcmp(g_command[i].tmp, str))
      i++;
    if (g_command[i].tmp)
      pars_cmd(g_command[i].n);
    else
      dprintf(2, "err command.\n");
    free(str);
  }
}
