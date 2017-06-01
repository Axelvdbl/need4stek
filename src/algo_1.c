/*
** algo_1.c for algo_1 in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 12:07:27 2017 Alexandre Chamard-bois
** Last update Thu Jun  1 12:44:38 2017 Alexandre Chamard-bois
*/

#include "command.h"

void  loop()
{
  float lidar_ray[32];
  float wheels;

  start();
  while (1)
  {
    lidar(lidar_ray);
    (lidar_ray[16] > 1000) ? forward(1) : forward(0.3);
    if (lidar_ray[1] > 600)
    {
      get_wheels(&wheels);
      wheels_dir( + wheels);
    }
    else if (lidar_ray[1] < 600)
    {
      get_wheels(&wheels);
      wheels_dir( + wheels);
    }
  }
}

int main()
{
  if (start() == -1)
    return (0);
  loop();
  stop();
}
