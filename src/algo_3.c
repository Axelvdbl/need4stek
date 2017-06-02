/*
** algo_3.c for algo_3 in /home/axel/projects/progress/CPE_2016_n4s/src/
**
** Made by Axel Vandenabeele
** Login   <axel.vandenabeele@epitech.eu>
**
** Started on  Fri Jun  2 13:59:29 2017 Axel Vandenabeele
** Last update Fri Jun  2 18:48:11 2017 Axel Vandenabeele
*/

#include "command.h"

void 	loop(float lid[32])
{
	while (1)
	{
		lidar(lid);
		(lid[16] > 1000) ? forward(0.5) : forward(0.2);
		lid[0] < 500 ? wheels_dir(-0.2) : wheels_dir(0.2);
		if (lid[0] == lid[31] && lid[16] < 600)
			break;
	}
}

int	main()
{
	float	lid[32];

	start();
	loop(lid);
	stop();
	return (0);
}
