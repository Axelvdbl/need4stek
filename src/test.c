/*
** main.c for ok in /home/alexandre/Downloads/n4s_package/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May  4 10:09:05 2017 Alexandre Chamard-bois
** Last update Thu May  4 12:11:48 2017 Alexandre Chamard-bois
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"

int main()
{
  int i;
  char *tab[35];
  char *str;

  my_puts("START_SIMULATION");
  if (!(str = get_next_line(0)))
    return (84);
  my_puts("CAR_FORWARD:1");
  if (!(str = get_next_line(0)))
    return (84);
  while (1)
  {
    my_puts("GET_INFO_LIDAR");
    if (!(str = get_next_line(0)))
      return (84);
    my_dprintf(2, "%s\n", str);
    i = 0;
    while (i < 35 && (tab[i] = my_strtok(str, ":")))
      i++;
    if (my_strstr(str, "Track Cleared") || my_getnbr(tab[19]) <= 600)
      break;
    free(str);
  }
  my_puts("CAR_FORWARD:0");
  if (!(str = get_next_line(0)))
    return (84);
  my_puts("CYCLE_WAIT:1");
  if (!(str = get_next_line(0)))
    return (84);
  my_dprintf(2, "fjizoefize\n");
  while (1);
  my_puts("STOP_SIMULATION");
  if (!(str = get_next_line(0)))
    return (84);
  my_dprintf(2, "%s\n", str);
  free(str);
  return (0);
}
