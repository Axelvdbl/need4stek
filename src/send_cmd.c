/*
** send_cmd.c for send_cmd in /home/axel/projects/progress/CPE_2016_n4s/src/
**
** Made by Axel Vandenabeele
** Login   <axel.vandenabeele@epitech.eu>
**
** Started on  Mon May 29 14:24:28 2017 Axel Vandenabeele
** Last update Tue May 30 22:07:22 2017 Axel Vandenabeele
*/

#include "my.h"

float	AVG(t_out* pars_out, int plc, int flt, int nbr_avg)
{
	float	my_avg;

	my_avg = pars_out->lidar[flt - 3] + pars_out->lidar[flt - 2];
	my_avg += pars_out->lidar[flt - 1] + pars_out->lidar[flt];
	return (my_avg / nbr_avg);
}

void 	get_avg(float lidar_avg, t_out* pars_out)
{
	int	nbr_avg;
	int	flt;
	int	plc;

	nbr_avg = 4;
	flt = 4;
	plc = 0;
	while (plc < 28)
	{
		lidar_avg[plc] = AVG(pars_out, plc, flt, nbr_avg);
		flt++;
		plc++;
	}
}

void 	algo_start(float lidar_avg, t_out* pars_out)
{
	int	max;

	start();
	lidar(pars_out);
	get_avg(lidar_avg, pars_out);
	max = get_max(lidar_avg);
	wheels_dir();
	(max > 1000) ? forward(1) : forward(0.2);
}

void 	algo_stop()
{
	stop();
}

int	get_max(float	lidar_avg)
{
	int	plc;
	int	max;

	plc = 0;
	max = -1;
	while (plc < 28)
	{
		max = (max > lidar_avg[plc]) ? lidar_avg[plc] : max);
		plc++;
	}
	return (max);
}

void 	send_cmd()
{
	t_out pars_out;
	float	lidar_avg[28];
	int	max;

	algo_start(lidar_avg, &pars_out);
	while (1)
	{
		get_avg(lidar_avg, &pars_out);
		max = get_max(lidar_avg);
	}
	algo_stop();
	return;
}
