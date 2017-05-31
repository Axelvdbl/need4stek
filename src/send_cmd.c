/*
** send_cmd.c for send_cmd in /home/axel/projects/progress/CPE_2016_n4s/src/
**
** Made by Axel Vandenabeele
** Login   <axel.vandenabeele@epitech.eu>
**
** Started on  Mon May 29 14:24:28 2017 Axel Vandenabeele
** Last update Wed May 31 14:46:11 2017 Axel Vandenabeele
*/

#include "command.h"

float	AVG(float lidar_pars[32], int flt, int nbr_avg)
{
	float	my_avg;

	my_avg = lidar_pars[flt - 3] + lidar_pars[flt - 2];
	my_avg += lidar_pars[flt - 1] + lidar_pars[flt];
	return (my_avg / nbr_avg);
}

void 	get_avg(float lidar_avg[28], float lidar_pars[32])
{
	int	nbr_avg;
	int	flt;
	int	plc;

	nbr_avg = 4;
	flt = 4;
	plc = 0;
	while (plc < 28)
	{
		lidar_avg[plc] = AVG(lidar_pars, flt, nbr_avg);
		flt++;
		plc++;
	}
}

int	get_max(float	lidar_avg[28])
{
	int	plc;
	int	max;

	plc = 0;
	max = -1;
	while (plc < 28)
	{
		max = ((max > lidar_avg[plc]) ? lidar_avg[plc] : max);
		plc++;
	}
	return (max);
}

void 	algo_start(float lidar_avg[28], float lidar_pars[32])
{
	int	max;

	start();
	lidar(lidar_pars);
	get_avg(lidar_avg, lidar_pars);
	max = get_max(lidar_avg);
	wheels_dir(0.5);
	(max > 1000) ? forward(1) : forward(0.2);
}

void 	send_cmd()
{
	float lidar_pars[32];
	float	lidar_avg[28];
	int	max;

	algo_start(lidar_avg, lidar_pars);
	while (1)
	{
		get_avg(lidar_avg, lidar_pars);
		max = get_max(lidar_avg);
	}
	stop();
	return;
}
