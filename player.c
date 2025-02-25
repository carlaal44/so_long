/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:08 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/18 11:21:27 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int keycode, t_game *game)
{
	int		new_x;
	int		new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 13)
		new_y--;
	if (keycode == 0)
		new_x--;
	if (keycode == 1)
		new_y++;
	if (keycode == 2)
		new_x++;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	draw_map(game);
}
