/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:13:45 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/17 17:28:27 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	init_game_constants(&game);
	if (argc != 2)
	{
		ft_printf("Error\nUse: ./so_long <mapa.ber>\n");
		return (1);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))
		|| ft_strlen(argv[1]) <= 4
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nThe map must have the extension .ber\n");
		return (1);
	}
	read_map(argv[1], &game);
	_validate_collectables(&game);
	_validate_player_count(&game);
	_validate_exit_count(&game);
	start_game(&game);
	return (0);
}
