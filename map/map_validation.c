/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:20:36 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/17 17:31:22 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	_validate_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			_map_error(game,
				"Error\nThe map is not surrounded by walls (up/down).");
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			_map_error(game,
				"Error\nThe map is not surrounded by walls (left/right).");
		y++;
	}
}

void	_validate_collectables(t_game *game)
{
	if (game->collectables < 1)
	{
		_map_error(game,
			"Error\nThe map must contain at least 1 collectible ('C').");
	}
}

void	_validate_player_count(t_game *game)
{
	int	player_count;
	int	x;
	int	y;

	player_count = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		_map_error(game, "Error\nThe map must contain exactly 1 player ('P').");
	}
}

void	_validate_exit_count(t_game *game)
{
	int	exit_count;
	int	x;
	int	y;

	exit_count = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	if (exit_count != 1)
	{
		_map_error(game, "Error\nThe map must contain exactly 1 exit ('E').");
	}
}
