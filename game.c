/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:04:52 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 17:27:36 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

void	load_game_assets(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img_ground = mlx_xpm_file_to_image(game->mlx, "suelo.xpm", &img_w, &img_h);
	if (!game->img_ground)
		ft_printf("Error: No se pudo cargar suelo.xpm\n");
	else
		ft_printf("suelo.xpm cargado. Dimensiones: %dx%d\n", img_w, img_h);

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "pared.xpm", &img_w, &img_h);
	if (!game->img_wall)
		ft_printf("Error: No se pudo cargar pared.xpm\n");
	else
		ft_printf("pared.xpm cargado. Dimensiones: %dx%d\n", img_w, img_h);

	game->img_player = mlx_xpm_file_to_image(game->mlx, "avatar.xpm", &img_w, &img_h);
	if (!game->img_player)
		ft_printf("Error: No se pudo cargar avatar.xpm\n");
	else
		ft_printf("avatar.xpm cargado. Dimensiones: %dx%d\n", img_w, img_h);

	game->img_collectible = NULL;
	game->img_exit = NULL;
}

void	draw_tile(t_game *game, int x, int y, char tile_type)
{
	if (game->img_ground)
		mlx_put_image_to_window(game->mlx, game->win, game->img_ground, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_pixel_put(game->mlx, game->win, x * TILE_SIZE, y * TILE_SIZE, 0x000000);
	_draw_specific_tile(game, x, y, tile_type);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: Fallo al inicializar MinilibX.\n");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "So_long");
	if (!game->win)
	{
		ft_printf("Error: Fallo al crear la ventana.\n");
		exit(1);
	}
	load_game_assets(game);
	draw_map(game);

	mlx_key_hook(game->win, move_player, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 9, 1L << 15, handle_render, game);
	mlx_hook(game->win, 22, 1L << 17, handle_render, game);

	mlx_loop(game->mlx);
}