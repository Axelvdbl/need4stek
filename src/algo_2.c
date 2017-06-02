/*
** algo_2.c for algo_2 in /home/axel/projects/progress/CPE_2016_n4s/src/
**
** Made by Axel Vandenabeele
** Login   <axel.vandenabeele@epitech.eu>
**
** Started on  Fri Jun  2 13:00:25 2017 Axel Vandenabeele
** Last update Fri Jun  2 13:58:39 2017 Axel Vandenabeele
*/

#include "command.h"

void 	turn(int *virage, float lid[32])
{
	lidar(lid);
	*virage = ((lid[0] > lid[31]) ? 1 : 2);
}

void 	loop(float lid[32])
{
	float	speed;
	int	virage;
	float	wheels;

	virage = 0;
	while (1)
	{
		lidar(lid);
		if (lid[16] > 1000)
			forward(1.0);
		else
			forward(lid[16] / 10000);
		if (lid[16] <= (get_speed(&speed) / 1000))
			break;
		if (lid[16] < 600)
			turn(&virage, lid);
		get_wheels(&wheels);
		if (virage != 0)
			(virage == 1) ? wheels_dir(lid[0] / 1000 + wheels) : wheels_dir(lid[31] / 1000 + wheels);
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
