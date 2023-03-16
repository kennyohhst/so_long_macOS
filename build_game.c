/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:38:00 by code              #+#    #+#             */
/*   Updated: 2023/03/16 16:36:15 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"

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

static void	draw_texture(t_god **game_data)
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

static void	put_textures(t_god **game_data)
{
	(*game_data)->textures->t_wall = mlx_load_png("./textures/wall.png");
	(*game_data)->textures->i_wall = mlx_texture_to_image((*game_data)->mlx,
			(*game_data)->textures->t_wall);
	(*game_data)->textures->t_joint = mlx_load_png("./textures/joint_1.png");
	(*game_data)->textures->i_joint = mlx_texture_to_image((*game_data)->mlx,
			(*game_data)->textures->t_joint);
	(*game_data)->textures->t_floor = mlx_load_png("./textures/floor.png");
	(*game_data)->textures->i_floor = mlx_texture_to_image((*game_data)->mlx,
			(*game_data)->textures->t_floor);
	(*game_data)->textures->t_exit = mlx_load_png("./textures/exit.png");
	(*game_data)->textures->i_exit = mlx_texture_to_image((*game_data)->mlx,
			(*game_data)->textures->t_exit);
	(*game_data)->textures->t_player = mlx_load_png("./textures/player.png");
	(*game_data)->textures->i_player = mlx_texture_to_image((*game_data)->mlx,
			(*game_data)->textures->t_player);
}

static void	mlx_instance(t_god **game_data)
{
	int	x;
	int	y;

	y = ft_strlen((*game_data)->full_map[0]);
	x = 0;
	while ((*game_data)->full_map[x] != NULL)
		x++;
	(*game_data)->mlx = mlx_init((y * 42), (x * 42), "so_long", true);
	if (!(*game_data)->mlx)
		exit(write(2, "Error\nmlx instance\n", 19));
}

void	build_game(t_god **game_data)
{
	mlx_instance(game_data);
	if (!(*game_data)->mlx)
		exit(write(2, "Error\nbuild_game\n", 17));
	put_textures(game_data);
	draw_texture(game_data);
	(*game_data)->moves = 0;
}
