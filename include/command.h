/*
** command.h for ok in /home/alexandre/Documents/tek1/CPE_2016_n4s/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 13:13:34 2017 Alexandre Chamard-bois
** Last update Mon May 29 21:49:33 2017 Alexandre Chamard-bois
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# define START          0 // START_SIMULATION     1
# define STOP           1 // STOP_SIMULATION      1
# define FORWARD        2 // CAR_FORWARD          1
# define BACKWARDS      3 // CAR_BACKWARDS        1
# define WHEELS_DIR     4 // WHEELS_DIR           1
# define LIDAR          5 // GET_INFO_LIDAR       2
# define GET_SPEED      6 // GET_CURRENT_SPEED    3
# define GET_WHEELS     7 // GET_CURRENT_WHEELS   3
# define WAIT           8 // CYCLE_WAIT           1
# define GET_SPEED_MAX  9 // GET_CAR_SPEED_MAX    3
# define GET_SPEED_MIN  10 // GET_CAR_SPEED_MIN   3
# define GET_SIMTIME    11 // GET_INFO_SIMTIME    4


typedef union   u_out
{
  float         lidar[32];
  float         get;
  long          stime[2];
}               t_out;

typedef struct  s_response
{
  int           value_id;
  char          code_str[128];
}               t_response;

int start();
int stop();
int forward(float nb);
int backwards(float nb);
int wheels_dir(float nb);
int lidar(t_out *pars_out);
int get_speed(t_out *pars_out);
int get_wheels(t_out *pars_out);
int cycle_wait(int nb);
int get_speed_max(t_out *pars_out);
int get_speed_min(t_out *pars_out);
int get_simtime(t_out *pars_out);

int recup_code1(char *str);
int recup_code2(char *str, t_out *pars_out);
int recup_code3(char *str, t_out *pars_out);
int recup_code4(char *str, t_out *pars_out);

#endif
