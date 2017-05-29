/*
** my_strlen.c for my_strlen in /home/Alex.Chamardbois/CPool/CPool_Day04
**
** Made by Alexandre Chamard-bois
** Login   <Alex.Chamardbois@epitech.net>
**
** Started on  Thu Oct  6 15:32:00 2016 Alexandre Chamard-bois
** Last update Mon May 29 15:18:24 2017 Alexandre Chamard-bois
*/

int		my_strlen(const char *str)
{
  int i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		my_tablen(char **tab)
{
  int i;

  if (!tab)
    return (0);
  i = 0;
  while (tab[i])
    i++;
  return (i);
}
