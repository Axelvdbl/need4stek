/*
** mystrtowordtab.c for  in /home/Alex.Chamardbois/CPool/CPool_Day08/task04
**
** Made by Alexandre Chamard-bois
** Login   <Alex.Chamardbois@epitech.net>
**
** Started on  Fri Oct 14 17:39:59 2016 Alexandre Chamard-bois
** Last update Tue May 30 22:38:58 2017 Alexandre Chamard-bois
*/

#include <stdlib.h>
#include "macro.h"

static int	nb_word(char *str)
{
	int i;
	int nbw;

	i = 0;
	nbw = 0;
	while (str[i])
	{
		if (str[i] == ':')
		{
			str[i] = 0;
			nbw++;
		}
		i++;
	}
	return (nbw);
}

char		**my_wordtab(char *str)
{
	char	**tab;
	int		nbw;
	int		i;
	int 	j;

	nbw = nb_word(str);
	if (!(tab = malloc(sizeof(char *) * (nbw + 2))))
		return (NULL);
	tab[0] = str;
	i = 0;
	j = 0;
	while (i <= nbw)
	{
		while (str[j])
			j++;
		tab[i + 1] = str + j + 1;
		j++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
