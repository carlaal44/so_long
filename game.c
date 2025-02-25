/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:18:51 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/18 11:28:48 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "So_long");
	draw_map(game);
	mlx_key_hook(game->win, move_player, game);
	mlx_loop(game->mlx);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_pixel_put(game->mlx, game->win, x * 32, y * 32, 0xFFFFFF);
			else if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				mlx_pixel_put(game->mlx, game->win, x * 32, y * 32, 0xFF0000);
			}
			x++;
		}
		y++;
	}
}
