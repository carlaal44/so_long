/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:08 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/17 17:31:00 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	_is_valid_player_move(t_game *game)
{
	if (game->new_px < 0 || game->new_px >= game->width
		|| game->new_py < 0 || game->new_py >= game->height)
		return (0);
	if (game->map[game->new_py][game->new_px] == '1')
		return (0);
	if (game->map[game->new_py][game->new_px] == 'E')
	{
		if (game->collectables == 0)
			return (1);
		else
		{
			ft_printf("You need to collect all the items to leave!\n");
			return (0);
		}
	}
	return (1);
}

static void	_update_new_coords_from_key(t_game *game, int keycode)
{
	if (keycode == 119)
		game->new_py--;
	else if (keycode == 115)
		game->new_py++;
	else if (keycode == 97)
		game->new_px--;
	else if (keycode == 100)
		game->new_px++;
}

static void	_execute_player_action(t_game *game, int old_px, int old_py)
{
	if (game->map[game->new_py][game->new_px] == 'C')
	{
		game->collectables--;
		ft_printf("Item collected! Remaining collectibles: %d\n",
			game->collectables);
	}
	else if (game->map[game->new_py][game->new_px] == 'E'
		&& game->collectables == 0)
	{
		game->moves++;
		ft_printf("Congratulations! You have won in %d moves.\n",
			game->moves);
		exit_game(game);
	}
	game->map[old_py][old_px] = '0';
	game->player_x = game->new_px;
	game->player_y = game->new_py;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	draw_map(game);
}

int	move_player(int keycode, t_game *game)
{
	int	old_px;
	int	old_py;

	old_px = game->player_x;
	old_py = game->player_y;
	game->new_px = game->player_x;
	game->new_py = game->player_y;
	ft_printf("Key pressed: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit_game(game);
	else
		_update_new_coords_from_key(game, keycode);
	if (old_px == game->new_px && old_py == game->new_py)
		return (0);
	if (_is_valid_player_move(game))
	{
		_execute_player_action(game, old_px, old_py);
	}
	else
		ft_printf("Error\nInvalid move.\n");
	return (0);
}
