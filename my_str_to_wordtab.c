/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/axel/project/en cours/PSU_2016_minishell1/
**
** Made by Axel Vandenabeele
** Login   <axel.vandenabeele@epitech.eu@epitech.eu>
**
** Started on  Wed Jan 18 11:05:17 2017 Axel Vandenabeele
** Last update Thu May  4 17:43:20 2017 Axel Vandenabeele
*/

#include "my.h"

int	my_ccmp(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**fill_arr(int count, char *c_str, char *sep)
{
	int	x;
	int	y;
	int	i;
	char	**arr;

	i = 0;
	y = 0;
	arr = malloc(sizeof(char *) * (count + 1));
	while (y < count)
	{
		arr[y] = malloc(sizeof(char) * my_strlen(c_str) + 1);
		x = 0;
		while (my_ccmp(c_str[i], sep) != 1 && c_str[i] != '\0')
		{
			arr[y][x] = c_str[i];
			x++;
			i++;
		}
		arr[y][x] = '\0';
		i++;
		y++;
	}
	arr[y] = NULL;
	return (arr);
}

int		count_words(char *str, char* sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((my_ccmp(str[i], sep) == 1) && my_ccmp(str[i + 1], sep) != 1 &&
				str[i + 1] != '\0')
					count++;
		i++;
	}
	return (count + 1);
}

char		*clean_str(char *str, char *sep)
{
	int		i;
	int		p;
	char	*c_str;

	i = 0;
	p = 0;
	c_str = malloc(sizeof(char) * my_strlen(str) + 1);
	while (my_ccmp(str[i], sep) == 1 && str[i])
		i++;
	while (str[i])
	{
		while (my_ccmp(str[i], sep) == 1 &&
					my_ccmp(str[i + 1], sep) == 1 && str[i])
			i++;
		c_str[p] = str[i];
		p++;
		i++;
	}
	c_str[p] = '\0';
	return (c_str);
}

char		**my_str_to_wordtab(char *str, char *sep)
{
	int		count;
	char	**arr;
	char	*c_str;

	c_str = clean_str(str, sep);
	count = count_words(c_str, sep);
	arr = fill_arr(count, c_str, sep);
	return (arr);
}
