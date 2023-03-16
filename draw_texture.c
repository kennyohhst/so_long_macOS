/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:17:09 by code              #+#    #+#             */
/*   Updated: 2023/03/15 18:20:38 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw(t_god **game_data, char c, int x, int y)
{
	if (c == '1')
		mlx_image_to_window((*game_data)->mlx,
			(*game_data)->textures->i_wall, x, y);
	else
		mlx_image_to_window((*game_data)->mlx,
			(*game_data)->textures->i_floor, x, y);
	if (c == 'C')
		mlx_image_to_window((*game_data)->mlx,
			(*game_data)->textures->i_joint, x, y);
	if (c == 'E')
		mlx_image_to_window((*game_data)->mlx,
			(*game_data)->textures->i_exit, x, y);
	if (c == 'P')
	{
		mlx_image_to_window((*game_data)->mlx,
			(*game_data)->textures->i_player, x, y);
		(*game_data)->p_x = x;
		(*game_data)->p_y = y;
	}
}

void	draw_texture(t_god **game_data)
{
	int	x;
	int	y;
	int	image_x;
	int	image_y;

	x = 0;
	y = 0;
	image_x = 0;
	image_y = 0;
	while ((*game_data)->full_map[y])
	{
		if ((*game_data)->full_map[y][x])
			draw(game_data, (*game_data)->full_map[y][x], image_x, image_y);
		image_x += 42;
		x++;
		if (!(*game_data)->full_map[y][x])
		{
			x = 0;
			y++;
			image_x = 0;
			image_y += 42;
		}
	}
}
