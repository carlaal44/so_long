/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:04:52 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/16 14:03:44 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

void	_load_image_asset(t_game *game, void **img_ptr,
			const char *path, const char *name)
{
	int	img_w;
	int	img_h;

	*img_ptr = mlx_xpm_file_to_image(game->mlx, (char *)path, &img_w, &img_h);
	if (!*img_ptr)
		ft_printf("Error: No se pudo cargar %s\n", name);
}

void	load_game_assets(t_game *game)
{
	_load_image_asset(game, &game->img_ground, "images/suelo.xpm", "suelo.xpm");
	_load_image_asset(game, &game->img_wall, "images/pared.xpm", "pared.xpm");
	_load_image_asset(game, &game->img_player, "images/avatar.xpm", "avatar.xpm");
	_load_image_asset(game, &game->img_collectible, "images/fruta.xpm", "fruta.xpm");
	_load_image_asset(game, &game->img_exit, "images/exit.xpm", "exit.xpm");
}

void	draw_tile(t_game *game, int x, int y, char tile_type)
{
	if (game->img_ground)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_ground, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_pixel_put(game->mlx, game->win,
			x * TILE_SIZE, y * TILE_SIZE, 0x000000);
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
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "So_long");
	if (!game->win)
	{
		ft_printf("Error: Fallo al crear la ventana.\n");
		exit(1);
	}
	load_game_assets(game);
	draw_map(game);
	mlx_key_hook(game->win, move_player, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 9, 1L << 5, handle_render, game);
	mlx_loop(game->mlx);
}
