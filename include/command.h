/*
** command.h for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 13:13:34 2017 Alexandre Chamard-bois
** Last update Mon May 29 14:50:15 2017 Alexandre Chamard-bois
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# define START          0 // START_SIMULATION
# define STOP           1 // STOP_SIMULATION
# define FORWARD        2 // CAR_FORWARD
# define BACKWARDS      3 // CAR_BACKWARDS
# define WHEELS_DIR     4 // WHEELS_DIR
# define LIDAR          5 // GET_INFO_LIDAR
# define GET_SPEED      6 // GET_CURRENT_SPEED
# define GET_WHEELS     7 // GET_CURRENT_WHEELS
# define WAIT           8 // CYCLE_WAIT
# define GET_SPEED_MAX  9 // GET_CAR_SPEED_MAX
# define GET_SPEED_MIN  10 // GET_CAR_SPEED_MIN
# define GET_SIMTIME    11 // GET_INFO_SIMTIME


typedef union   u_out
{
  float         lidar[32];
  float         get;
  long          stime[2];
}               t_out;

int start(t_out *pars_out);
int stop(t_out *pars_out);
int forward(t_out *pars_out, float nb);
int backwards(t_out *pars_out, float nb);
int wheels_dir(t_out *pars_out, float nb);
int lidar(t_out *pars_out);
int get_wheels(t_out *pars_out);
int cylce_wait(t_out *pars_out, int nb);
int get_speed_max(t_out *pars_out);
int get_speed_min(t_out *pars_out);
int get_simtime(t_out *pars_out);

#endif
