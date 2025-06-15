/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:04:13 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 17:14:12 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"

# define TILE_SIZE 93

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectables;
	int		moves;

	void	*img_player;
	void	*img_wall;
	void	*img_ground;
	void	*img_collectible;
	void	*img_exit;

}	t_game;

// Funciones principales del juego
void	read_map(char *file, t_game *game);
void	start_game(t_game *game);
int		move_player(int keycode, t_game *game); // Implementado en player.c
void	free_map(t_game *game);

// Funciones de dibujo y assets (implementadas en game.c y drawing_utils.c)
void	load_game_assets(t_game *game);
void	draw_map(t_game *game);
void	draw_tile(t_game *game, int x, int y, char tile_type);
void	_draw_specific_tile(t_game *game, int x, int y, char tile_type); // Implementado en drawing_utils.c

// Funciones auxiliares de dibujo para cada tipo de baldosa (implementadas en drawing_utils.c)
void	_draw_wall_tile(t_game *game, int x, int y);
void	_draw_player_tile(t_game *game, int x, int y);
void	_draw_collectible_tile(t_game *game, int x, int y);
void	_draw_exit_tile(t_game *game, int x, int y);

// Funciones de manejo de eventos (implementadas en events.c o drawing_utils.c)
int		exit_game(t_game *game); // Para el botón 'X' y ESC
int		handle_render(t_game *game); // Para redibujar la ventana (evento Expose)

#endif

