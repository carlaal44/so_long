/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:35:59 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 19:19:05 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	_draw_wall_tile(t_game *game, int x, int y)
{
	if (game->img_wall)
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_pixel_put(game->mlx, game->win,
			x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF);
}

void	_draw_player_tile(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	if (game->img_player)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_pixel_put(game->mlx, game->win,
			x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
}

void	_draw_collectible_tile(t_game *game, int x, int y)
{
	if (game->img_collectible)
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_pixel_put(game->mlx, game->win,
			x * TILE_SIZE, y * TILE_SIZE, 0x00FF00);
}

void	_draw_exit_tile(t_game *game, int x, int y)
{
	if (game->img_exit)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_pixel_put(game->mlx, game->win,
			x * TILE_SIZE, y * TILE_SIZE, 0x0000FF);
}

void	_draw_specific_tile(t_game *game, int x, int y, char tile_type)
{
	if (tile_type == '1')
		_draw_wall_tile(game, x, y);
	else if (tile_type == 'P')
		_draw_player_tile(game, x, y);
	else if (tile_type == 'C')
		_draw_collectible_tile(game, x, y);
	else if (tile_type == 'E')
		_draw_exit_tile(game, x, y);
}
