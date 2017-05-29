/*
** mystrtowordtab.c for  in /home/Alex.Chamardbois/CPool/CPool_Day08/task04
**
** Made by Alexandre Chamard-bois
** Login   <Alex.Chamardbois@epitech.net>
**
** Started on  Fri Oct 14 17:39:59 2016 Alexandre Chamard-bois
** Last update Mon May 29 22:10:02 2017 Alexandre Chamard-bois
*/

#include <stdlib.h>
#include "macro.h"

int is_sep(const char *sep, char c)
{
	while (sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	nb_word(const char *str, const char *sep)
{
	int in_word;
  int nb_word;

  nb_word = 0;
  if (!is_sep(sep, *str))
    in_word = 0;
  else
  {
    in_word = 1;
    nb_word = 1;
  }
  while (*str)
  {
    if (!is_sep(sep, *str) && in_word == 0)
      nb_word++;
    if (is_sep(sep, *str))
      in_word = 0;
    else
      in_word = 1;
    str++;
  }
  return (nb_word);
}

int	size_word(const char *str, const char *sep)
{
  int i;

  i = 0;
  while (str[i] && !is_sep(sep, str[i]))
    i++;
  return (i);
}

int		get_word(char *tab, const char *str, const char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !is_sep(sep, str[i]))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = 0;
	return (i);
}

char		**my_wordtab(const char *str, const char *sep)
{
	char	**tab;
	int		i;
	int		j;

	i = nb_word(str, sep);
	if (!(tab = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	j = i;
	while (j > 0)
	{
		while (*str == ' ')
			str++;
		if (!(tab[i - j] = malloc(sizeof(char) * (size_word(str, sep) + 1))))
			return (NULL);
		str += get_word(tab[i - j], str, sep);
		j--;
	}
	tab[i] = NULL;
	return (tab);
}
