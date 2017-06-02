/*
** my_main.c for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 21:47:48 2017 Alexandre Chamard-bois
** Last update Fri Jun  2 18:36:19 2017 Axel Vandenabeele
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

void loop()
{
  float dir[5];
  float current;
  float max;
  float min;
  float wheel;
  float speed;

  while (1)
  {
    avg(dir);
    max = get_max(dir);
    min = get_min(dir);
    //dprintf(2, "max: %f\tmin: %f\n", max, min);
    // speed = SPEED(max, dir);
    speed = min > 1000 ? .6 : min > 400 ? .4 : .2;
    wheel = (min == dir[1] ? -0.4 : min == dir[0] ? -0.2 :
            min == dir[3] ? 0.4 : min == dir[4] ? 0.2 :
            dir[0] < dir[4] ? 0.4 : -0.4);
    get_speed(&current);
    if (min < 100 || current == 0)
      wheel *= 2;
    // if (current == 0)
    // wheel = (max == dir[2] ? 0 : max == dir[1] ? 0.2 :
    //         max == dir[3] ? -0.2 : max == dir[0] ? 0.4 : -0.4);
    //dprintf(2, "speed: %f\nwheel: %f\n", speed, wheel);
    if (speed > 0)
      forward(speed);
    // get_wheels(&current);
    // if (current != wheel)
      wheels_dir(wheel);
  }
}

int main()
{
  if (start() == -1)
    return (0);
  loop();
  stop();
}
