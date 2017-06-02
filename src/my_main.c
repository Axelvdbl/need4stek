/*
** my_main.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 21:47:48 2017 Alexandre Chamard-bois
** Last update Fri Jun  2 10:59:47 2017 Alexandre Chamard-bois
*/

#include <stdio.h>
#include <string.h>
#include "macro.h"
#include "command.h"

float get_max(float dir[5])
{
  int i;
  float max;

  max = dir[0];
  i = 0;
  while (i < 5)
  {
    if (max < dir[i])
      max = dir[i];
    i++;
  }
  return (max);
}

float get_min(float dir[5])
{
  int i;
  float min;

  min = dir[0];
  i = 0;
  while (i < 5)
  {
    if (min > dir[i])
      min = dir[i];
    i++;
  }
  return (min);
}

void avg(float dir[5])
{
  float lid[32];

  lidar(lid);
  dir[0] = (lid[0] + lid[1] + lid[2] + lid[3] +
            lid[4] + lid[5] + lid[6]) / 7;
  dir[1] = (lid[7] + lid[8] + lid[9] + lid[10] +
            lid[11] + lid[12] + lid[13]) / 7;
  dir[2] = (lid[14] + lid[15] + lid[16] + lid[17]) / 4;
  dir[3] = (lid[18] + lid[19] + lid[20] + lid[21] +
            lid[22] + lid[23] + lid[24]) / 7;
  dir[4] = (lid[25] + lid[26] + lid[27] + lid[28] +
            lid[29] + lid[30] + lid[31]) / 7;
}

int verif_hit(float wheel)
{
  float current;
  static float max = 0;

  if (!max)
    get_speed_max(&max);
  get_speed(&current);
  if (current < max * 0.03)
  {
    dprintf(2, "dkazdiojaodiajzdoiazjd\n");
    wheels_dir(wheel < 0 ? 1 : -1);
    backwards(0.1);
    cycle_wait(6);
    backwards(0.5);
    cycle_wait(3);
    wheels_dir(wheel < 0 ? -1 : 0);
    forward(0.5);
    cycle_wait(6);
    forward(0.2);
    cycle_wait(3);
    return (0);
  }
  return (1);
}

float goooooo()
{
  float current;

  get_speed(&current);
  return (0);
}

void loop()
{
  float dir[5];
  float min;
  float wheel;
  float speed;

    avg(dir);
    min = get_min(dir);
    speed = min > 1000 ? .6 : min > 500 ? .4 : min > 150 ? .3 : 0;
    if (min < 600)
      wheel = (min == dir[1] ? -0.6 : min == dir[0] ? -0.3 :
            min == dir[3] ? 0.6 : min == dir[4] ? 0.3 :
            dir[0] < dir[4] ? 0.4 : -0.4);
    else
      wheel = (min == dir[1] ? 0.2 : min == dir[0] ? 0.1 :
              min == dir[3] ? -0.2 : min == dir[4] ? -0.1 : 0);
    if (min < 100)
      wheel *= 1.5;
    if (dir[2] >= 800 && dir[1] >= 300 && dir[3] >= 300 &&
                          dir[0] >= 100 && dir[4] >= 100)
    {
      wheel = goooooo();
      speed = .7;
    }
    forward(speed);
    wheels_dir(wheel);
  loop();
}

int main()
{
  if (start() == -1)
    return (0);
  forward(0.1);
  cycle_wait(3);
  loop();
  stop();
}
