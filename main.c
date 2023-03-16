/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2023/03/16 16:29:32 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_god			*game_data;
	char			**temp;

	if (argc != 2)
		exit((write(2, "Error\ncheck input\n", 18)));
	game_data = malloc(sizeof(t_god));
	game_data->textures = malloc(sizeof(t_game));
	if (!game_data || !game_data->textures)
		exit(write(2, "error\ngame/full_map error\n", 26));
	game_data->full_map = parse(&temp, argv[1]);
	check_map(game_data->full_map);
	game_data->collectables = prep_flood(temp);
	ft_free_s(temp);
	build_game(&game_data);
	mlx_key_hook(game_data->mlx, &run_game, game_data);
	mlx_loop(game_data->mlx);
	mlx_terminate(game_data->mlx);
	ft_free_s(game_data->full_map);
	return (0);
}
