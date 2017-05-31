/*
** command.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 11:44:03 2017 Alexandre Chamard-bois
** Last update Tue May 30 22:39:12 2017 Alexandre Chamard-bois
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libmy.h"
#include "command.h"

int recup_code1(char *str)
{
  int   nb;
  char  status[3][128];

  memset(status, 0, 3 * 128);
  if (sscanf(str, "%d:%[^:]:%[^:]:%[^\n]", &nb, status[0], status[1],
            status[2]) != 4)
    return (-1);
  dprintf(2, "%d:%s:%s:%s\n", nb, status[0], status[1], status[2]);
  if (strcmp(status[0], "OK"))
    return (-1);
  return (nb);
}

int recup_code2(char *str, float lid[32])
{
  int   i;
  int   nb;
  char  **tab;

  if (!(tab = my_wordtab(str)) || my_tablen(tab) < 35)
  {
    if (tab)
      free_tab(tab);
    return (-1);
  }
  nb = atoi(tab[0]);
  dprintf(2, "%d:%s:%s:%s\n", nb, tab[1], tab[2], tab[35]);
  i = 0;
  while (i < 32)
  {
    lid[i] = atof(tab[i + 3]);
    i++;
  }
  if (strcmp(tab[1], "OK"))
    return (-1);
  free(tab);
  return (nb);
}

int recup_code3(char *str, float *get)
{
  int   nb;
  char  status[3][128];

  memset(status, 0, 3 * 128);
  if (sscanf(str, "%d:%[^:]:%[^:]:%f:%[^\n]", &nb, status[0], status[1],
      get, status[2]) != 5)
    return (-1);
  dprintf(2, "%d:%s:%s:%s\n", nb, status[0], status[1], status[2]);
  if (strcmp(status[0], "OK"))
    return (-1);
  return (nb);
}

int recup_code4(char *str, long stime[2])
{
  int   nb;
  char  status[3][128];

  memset(status, 0, 3 * 128);
  if (sscanf(str, "%d:%[^:]:%[^:]:[%ld,%ld]:%[^\n]", &nb, status[0],
      status[1], stime, stime + 1, status[2]) != 6)
    return (-1);
  dprintf(2, "%d:%s:%s:%s\n", nb, status[0], status[1], status[2]);
  if (strcmp(status[0], "OK"))
    return (-1);
  return (nb);
}
