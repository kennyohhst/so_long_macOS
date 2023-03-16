/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:21:18 by code              #+#    #+#             */
/*   Updated: 2023/03/13 16:18:08 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strchr(char *s, int c)
{
	int	i;
	int	slen;
	int	count;

	count = 0;
	i = 0;
	slen = ft_strlen(s);
	while (i <= slen)
	{
		if (s[i] == (char)c)
			count++;
		i++;
	}
	return (count);
}

static void	one_of_each(char **full_map, char c)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (full_map[i])
	{
		x += ft_strchr(full_map[i], c);
		if (x > 1 && c != 'C')
			exit(write(2, "Error\none_of_each_1\n", 20));
		i++;
	}
	if (x < 1)
		exit(write(2, "Error\none_of_each_2\n", 20));
}

static int	correct_char(char *s)
{
	int	i;
	int	slen;

	i = 0;
	slen = ft_strlen(s);
	while (i < slen)
	{
		if (s[i] != '0' && s[i] != '1')
			if (s[i] != 'P' && s[i] != 'C' && s[i] != 'E')
				return (0);
		i++;
	}
	return (1);
}

static int	check_char(char **full_map)
{
	int	i;

	i = 0;
	if (!full_map)
		return (1);
	while (full_map[i] != NULL)
	{
		if (!correct_char(full_map[i]))
			return (1);
		i++;
	}
	one_of_each(full_map, 'P');
	one_of_each(full_map, 'E');
	one_of_each(full_map, 'C');
	return (0);
}

void	check_map(char **full_map)
{
	if (check_char(full_map))
		exit(write(2, "Error\ncheck_map_1\n", 18));
}
