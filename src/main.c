/*
** main.c for ok in /home/alexandre/Downloads/n4s_package/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May  4 10:09:05 2017 Alexandre Chamard-bois
** Last update Thu May  4 12:20:29 2017 Axel Vandenabeele
*/

#include "libmy.h"
#include <stdlib.h>

int main()
{
  char *str;
	char	*tab[35];
	int	i;

  my_puts("START_SIMULATION");
	if (!(str = get_next_line((0))))
		return (84);
	my_puts("CAR_FORWARD:0.5");
	if (!(str = get_next_line((0))))
		return (84);
  while (1)
  {
		i = 0;
		my_puts("GET_INFO_LIDAR");
		if (!(str = get_next_line((0))))
			return (84);
		while (i < 35 && (tab[i] = my_strtok(str, ":")) != NULL)
			i++;
		if (my_getnbr(tab[19]) < 600)
			break;
	}
	my_puts("CAR_FORWARD:0");
	if (!(str = get_next_line((0))))
		return (84);
	my_puts("CYCLE_WAIT:20");
	if (!(str = get_next_line((0))))
		return (84);
  my_puts("STOP_SIMULATION");
	if (!(str = get_next_line((0))))
		return (84);
  return (0);
}
