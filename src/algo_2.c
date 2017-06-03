/*
** algo_2.c for algo_2 in /home/axel/projects/progress/CPE_2016_n4s/src/
**
** Made by Axel Vandenabeele
** Login   <axel.vandenabeele@epitech.eu>
**
** Started on  Fri Jun  2 13:00:25 2017 Axel Vandenabeele
** Last update Sat Jun  3 22:06:20 2017 Axel Vandenabeele
*/

#include "command.h"

void 	set_dir(float *speed, float lid[32])
{
	float	wheels;

	if (*speed >= 0.6)
		wheels = 0;
	else if (*speed >= 0.2)
		wheels = 0.2 - 0.5 * *speed + 0.1;
	else
		wheels = 0.2 + 0.5 * *speed + 0.05;
	if (lid[0] - lid[31] < 0)
		wheels = -wheels;
	wheels_dir(wheels);
}

void 	loop(float lid[32])
{
	float	speed;

	while (1)
	{
		lidar(lid);
		speed = lid[15] / 3100;
		forward(speed);
		set_dir(&speed, lid);
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
