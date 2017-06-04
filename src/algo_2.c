/*
** algo_2.c for algo_2 in /home/axel/projects/progress/CPE_2016_n4s/src/
**
** Made by Axel Vandenabeele
** Login   <axel.vandenabeele@epitech.eu>
**
** Started on  Fri Jun  2 13:00:25 2017 Axel Vandenabeele
** Last update Sun Jun  4 08:49:18 2017 alexandre Chamard-bois
*/

#include "command.h"

int	set_dir(float *speed, float lid[32])
{
  float	wheels;
  int	rep;

  if (*speed >= 0.6)
    wheels = 0;
  else if (*speed >= 0.2)
    wheels = 0.2 - 0.5 * *speed + 0.1;
  else
    wheels = 0.2 + 0.5 * *speed + 0.05;
  if (lid[0] - lid[31] < 0)
    wheels = -wheels;
  if ((rep = wheels_dir(wheels)) && verif_rep(rep))
    return (rep);
  return (0);
}

int	loop(float lid[32])
{
  float	speed;
  int	rep;

  while (1)
    {
      if ((rep = lidar(lid)) && verif_rep(rep))
	return (rep);
      speed = lid[15] / 3100;
      if ((rep = forward(speed)) && verif_rep(rep))
	return (rep);
      if ((rep = set_dir(&speed, lid)))
	return (rep);
    }
}

int	main()
{
  float	lid[32];

  start();
  if (loop(lid) == 4)
    return (84);
  stop();
  return (0);
}
