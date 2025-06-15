/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:35:59 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 17:17:17 by carfern2         ###   ########.fr       */
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

// Implementación de la función auxiliar para dibujar el tile del jugador
void	_draw_player_tile(t_game *game, int x, int y)
{
	int	offset_x;
	int	offset_y;

	game->player_x = x;
	game->player_y = y;
	offset_x = (TILE_SIZE - 63) / 2; // Centrar el jugador horizontalmente
	offset_y = TILE_SIZE - 63;       // Posicionar el jugador en la parte inferior
	if (game->img_player)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			(x * TILE_SIZE) + offset_x, (y * TILE_SIZE) + offset_y);
	else
		mlx_pixel_put(game->mlx, game->win,
			x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
}

// Implementación de la función auxiliar para dibujar el tile de coleccionable
void	_draw_collectible_tile(t_game *game, int x, int y)
{
	if (game->img_collectible)
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_pixel_put(game->mlx, game->win,
			x * TILE_SIZE, y * TILE_SIZE, 0x00FF00);
}

// Implementación de la función auxiliar para dibujar el tile de salida
void	_draw_exit_tile(t_game *game, int x, int y)
{
	if (game->img_exit)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_pixel_put(game->mlx, game->win,
			x * TILE_SIZE, y * TILE_SIZE, 0x0000FF);
}

// Esta función principal delega el dibujo específico a las auxiliares
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

