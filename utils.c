/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:41 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/16 13:51:43 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

void	free_map(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
}

int	handle_render(t_game *game)
{
	draw_map(game);
	return (0);
}
