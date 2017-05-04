/*
** main.c for ok in /home/alexandre/Downloads/n4s_package/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May  4 10:09:05 2017 Alexandre Chamard-bois
** Last update Thu May  4 11:06:01 2017 Alexandre Chamard-bois
*/

#include "libmy.h"

int main()
{
  char str[1024];
  // int i = 0;

  my_memset(str, 0, 1024);
  my_puts("START_SIMULATION");
  while (1)
  {
    my_puts("CAR_FORWARD:1");
    my_puts("GET_INFO_LIDAR");
  }
  my_puts("STOP_SIMULATION");
  return (0);
}
