/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:17:01 by code              #+#    #+#             */
/*   Updated: 2023/03/15 19:21:43 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	middle_walls(char *full_map)
{
	if (full_map[0] != '1' || full_map[ft_strlen(full_map) - 1] != '1')
		exit(write(2, "Error\nmiddle_walls_1\n", 21));
}

static void	first_last_wall(char *first_last_wall)
{
	int	i;

	i = 0;
	while (first_last_wall[i] == ' ')
		i++;
	while (first_last_wall[i] != '\0')
	{
		if (first_last_wall[i] != '1')
			exit(write(2, "Error\nfirst_last_wall_1\n", 24));
		i++;
	}	
}

static void	check_shape(char **full_map)
{
	size_t	length_wall;
	size_t	i;

	if (!full_map)
		exit(write(2, "Error\nempty map\n", 16));
	first_last_wall(full_map[0]);
	i = 1;
	length_wall = ft_strlen(full_map[0]);
	while (full_map[i])
	{
		if (ft_strlen(full_map[i]) != length_wall)
			exit(write(2, "Error\ncheck_shape_1\n", 20));
		middle_walls(full_map[i]);
		i++;
	}
	first_last_wall(full_map[i - 1]);
}

char	**parse(char ***temp, char *map_input)
{
	int		fd;
	char	*temp_str;
	char	*str;
	char	**full_map;

	str = NULL;
	fd = open(map_input, O_RDONLY);
	if (fd < 0)
		exit(write(2, "Error\nfd\n", 9));
	temp_str = get_next_line(fd);
	while (temp_str)
	{
		if (temp_str[0] == '\n')
			exit(write(2, "Error\nnew_line_error_1\n", 23));
		str = strljoin(str, temp_str, strlen(temp_str), 0);
		free(temp_str);
		temp_str = get_next_line(fd);
	}
	full_map = ft_split(str, '\n');
	(*temp) = ft_split(str, '\n');
	check_shape(full_map);
	free(str);
	close(fd);
	return (full_map);
}
