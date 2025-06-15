/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:08 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 19:29:15 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->width ||
		new_y < 0 || new_y >= game->height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

int	move_player(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	ft_printf("Key pressed: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit_game(game);
	if (keycode == 119)
		new_y--;
	else if (keycode == 115)
		new_y++;
	else if (keycode == 97)
		new_x--;
	else if (keycode == 100)
		new_x++;
	if (is_valid_move(game, new_x, new_y))
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves++;
		ft_printf("Movimientos: %d\n", game->moves);
		draw_map(game);
	}
	else
		ft_printf("Movimiento inválido (pared o fuera de límites)\n");
	return (0);
}
