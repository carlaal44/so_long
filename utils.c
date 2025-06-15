/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:41 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 17:17:20 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"         // Para las funciones de libft
#include "get_next_line.h" // Para get_next_line
#include "ft_printf.h"     // Para ft_printf
#include "mlx.h"           // Para MinilibX
#include "so_long.h"       // Tu propia cabecera de so_long, si la tienes

void	free_map(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

int	handle_render(t_game *game)
{
	draw_map(game);
	return (0);
}
