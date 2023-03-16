/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:48:31 by code              #+#    #+#             */
/*   Updated: 2023/03/16 16:44:42 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key_left(mlx_key_data_t keydata, t_god *data)
{
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (data->full_map[data->p_y / 42][(data->p_x / 42) - 1] != '1')
		{
			mlx_image_to_window(data->mlx, data->textures->i_floor,
				data->p_x, data->p_y);
			data->p_x -= 42;
			if (data->full_map[data->p_y / 42][(data->p_x / 42) + 1] == 'E')
				mlx_image_to_window(data->mlx, data->textures->i_exit,
					(data->p_x + 42), data->p_y);
			if (data->full_map[data->p_y / 42][data->p_x / 42] == 'C')
			{
				data->full_map[data->p_y / 42][data->p_x / 42] = '0';
				data->collectables -= 1;
			}
			data->moves++;
			ft_printf("moves:	%d\n", data->moves);
		}
	}
}

static void	key_right(mlx_key_data_t keydata, t_god *data)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (data->full_map[(data->p_y / 42)][(data->p_x / 42) + 1] != '1')
		{
			mlx_image_to_window(data->mlx, data->textures->i_floor,
				data->p_x, data->p_y);
			data->p_x += 42;
			if (data->full_map[data->p_y / 42][(data->p_x / 42) - 1] == 'E')
				mlx_image_to_window(data->mlx, data->textures->i_exit,
					(data->p_x - 42), data->p_y);
			if (data->full_map[data->p_y / 42][data->p_x / 42] == 'C')
			{
				data->full_map[data->p_y / 42][data->p_x / 42] = '0';
				data->collectables -= 1;
			}
			data->moves++;
			ft_printf("moves:	%d\n", data->moves);
		}	
	}
}

static void	key_down(mlx_key_data_t keydata, t_god *data)
{
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (data->full_map[(data->p_y / 42) + 1][data->p_x / 42] != '1')
		{
			mlx_image_to_window(data->mlx, data->textures->i_floor,
				data->p_x, data->p_y);
			data->p_y += 42;
			if (data->full_map[(data->p_y / 42) - 1][(data->p_x / 42)] == 'E')
				mlx_image_to_window(data->mlx, data->textures->i_exit,
					data->p_x, (data->p_y - 42));
			if (data->full_map[data->p_y / 42][data->p_x / 42] == 'C')
			{
				data->full_map[data->p_y / 42][data->p_x / 42] = '0';
				data->collectables -= 1;
			}
			data->moves++;
			ft_printf("moves:	%d\n", data->moves);
		}	
	}	
}

static void	key_up(mlx_key_data_t keydata, t_god *data)
{
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		if (data->full_map[(data->p_y / 42) - 1][data->p_x / 42] != '1')
		{
			mlx_image_to_window(data->mlx, data->textures->i_floor,
				data->p_x, data->p_y);
			data->p_y -= 42;
			if (data->full_map[(data->p_y / 42 + 1)][(data->p_x / 42)] == 'E')
				mlx_image_to_window(data->mlx, data->textures->i_exit,
					data->p_x, (data->p_y + 42));
			if (data->full_map[data->p_y / 42][data->p_x / 42] == 'C')
			{
				data->full_map[data->p_y / 42][data->p_x / 42] = '0';
				data->collectables -= 1;
			}
			data->moves++;
			ft_printf("moves:	%d\n", data->moves);
		}	
	}
}

void	run_game(mlx_key_data_t keydata, void *game_data)
{
	t_god	*data;

	data = (t_god *) game_data;
	key_up(keydata, data);
	key_down(keydata, data);
	key_left(keydata, data);
	key_right(keydata, data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(write(2, "escape pressed\n", 15));
	data->textures->i_player->instances[0].x = data->p_x;
	data->textures->i_player->instances[0].y = data->p_y;
	mlx_image_to_window(data->mlx, data->textures->i_player,
		data->p_x, data->p_y);
	if (data->collectables <= 0
		&& data->full_map[(data->p_y / 42)][data->p_x / 42] == 'E')
	{
		data->moves += 1;
		exit(write(1, "finished, congrats!\n", 20));
	}
}
