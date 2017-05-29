/*
** command.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 11:44:03 2017 Alexandre Chamard-bois
** Last update Mon May 29 14:50:49 2017 Alexandre Chamard-bois
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libmy.h"
#include "command.h"

int recup_code1(char *str, t_out *pars_out)
{
  int   nb;
  char  status[3][128];

  (void) pars_out;
  memset(status, 0, 3 * 128);
  if (sscanf(str, "%d:%[^:]:%[^:]:%s",
      &nb, status[0], status[1], status[2]) != 4)
    return (-1);
  printf("%d\n%s\n%s\n", nb, status[0], status[1]);
  return (nb);
}

int recup_code2(char *str, t_out *pars_out)
{
  int   nb;
  char  status[3][128];

  (void) pars_out;
  memset(status, 0, 3 * 128);
  if (sscanf(str, "%d:%[^:]:%[^:]:%s",
      &nb, status[0], status[1], status[2]) != 4)
    return (-1);
  printf("%d\n%s\n%s\n", nb, status[0], status[1]);
  return (nb);
}

int recup_code3(char *str, t_out *pars_out)
{
  int   nb;
  char  status[3][128];

  (void) pars_out;
  memset(status, 0, 3 * 128);
  if (sscanf(str, "%d:%[^:]:%[^:]:%f:%s",
      &nb, status[0], status[1], &pars_out->get, status[2]) != 5)
    return (-1);
  printf("%d\n%s\n%s\nfloat: %f\n", nb, status[0], status[1], pars_out->get);
  return (nb);
}

int recup_code4(char *str, t_out *pars_out)
{
  int   nb;
  char  status[3][128];

  (void) pars_out;
  memset(status, 0, 3 * 128);
  if (sscanf(str, "%d:%[^:]:%[^:]:[%ld,%ld]:%s", &nb, status[0], status[1],
      &pars_out->stime[0], &pars_out->stime[1], status[2]) != 6)
    return (-1);
  printf("%d\n%s\n%s\n", nb, status[0], status[1]);
  return (nb);
}

int main()
{
  int i;
  t_out pars_out;
  char *str;

  while ((str = get_next_line(0)))
  {
    i = 0;
    while (g_command[i].tmp && strcmp(g_command[i].tmp, str))
      i++;
    if (g_command[i].tmp)
      pars_cmd(g_command[i].n, &pars_in, &pars_out);
    else
      dprintf(2, "err command.\n");
    free(str);
  }
}
