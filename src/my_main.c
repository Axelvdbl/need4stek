/*
** my_main.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 21:47:48 2017 Alexandre Chamard-bois
** Last update Wed May 31 10:25:06 2017 Alexandre Chamard-bois
*/

#include <stdio.h>
#include "macro.h"
#include "command.h"

double avg(float *tab, int nb)
{
  int i;
  double avg;

  i = 0;
  avg = 0;
  while (i < nb)
  {
    avg += *(tab + i);
    i++;
  }
  return (avg / (double) nb);
}

#define SIZE_AVG 7

int main()
{
  float get;
  long ti[2];

  if (start() == -1)
    return (0);
  get_speed_min(&get);
  dprintf(2, "min: %f\n", get);
  get_speed_max(&get);
  dprintf(2, "max: %f\n", get);
  for (int i = 0; i < 50; i++)
  {
    cycle_wait(3);
    get_simtime(ti);
    dprintf(2, "%ld : %ld\n", ti[0], ti[1]);
  }
  cycle_wait(42);
  stop();
}
