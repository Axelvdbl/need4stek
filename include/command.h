/*
** command.h for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 13:13:34 2017 Alexandre Chamard-bois
** Last update Wed May 31 09:07:00 2017 Alexandre Chamard-bois
*/

#ifndef COMMAND_H_
# define COMMAND_H_

int start();
int stop();
int forward(float nb);
int backwards(float nb);
int wheels_dir(float nb);
int lidar(float lid[32]);
int get_speed(float *get);
int get_wheels(float *get);
int cycle_wait(int nb);
int get_speed_max(float *get);
int get_speed_min(float *get);
int get_simtime(long stime[2]);

int recup_code1(char *str);
int recup_code2(char *str, float lid[32]);
int recup_code3(char *str, float *get);
int recup_code4(char *str, long stime[2]);

#endif
