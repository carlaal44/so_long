/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_constants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:56:39 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/17 14:57:05 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_constants(t_game *game)
{
	game->dirs.dx[0] = 0;
	game->dirs.dx[1] = 0;
	game->dirs.dx[2] = 1;
	game->dirs.dx[3] = -1;
	game->dirs.dy[0] = 1;
	game->dirs.dy[1] = -1;
	game->dirs.dy[2] = 0;
	game->dirs.dy[3] = 0;
}
