/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:04:13 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/17 14:58:14 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "libft.h"

# define TILE_SIZE 93

typedef struct s_queue_node
{
	int	x;
	int	y;
}	t_queue_node;

typedef struct s_bfs_data
{
	int	front;
	int	rear;
	int	i;
}	t_bfs_data;

typedef struct s_direction_vectors
{
	int	dx[4];
	int	dy[4];
}	t_direction_vectors;

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

	int		new_px;
	int		new_py;

	char	*map_full_str_builder;

	int		path_reachable_collectables;
	int		path_reachable_exit;

	int		temp_player_count;
	int		temp_exit_count;

	t_direction_vectors	dirs;

	void	*img_player;
	void	*img_wall;
	void	*img_ground;
	void	*img_collectible;
	void	*img_exit;

}	t_game;

void	read_map(char *file, t_game *game);
void	start_game(t_game *game);
int		move_player(int keycode, t_game *game);
void	free_map(t_game *game);

void	load_game_assets(t_game *game);
void	draw_map(t_game *game);
void	draw_tile(t_game *game, int x, int y, char tile_type);
void	_load_image_asset(t_game *game, void **img_ptr,
			const char *path, const char *name);

void	_draw_specific_tile(t_game *game, int x, int y, char tile_type);
void	_draw_wall_tile(t_game *game, int x, int y);
void	_draw_player_tile(t_game *game, int x, int y);
void	_draw_collectible_tile(t_game *game, int x, int y);
void	_draw_exit_tile(t_game *game, int x, int y);

int		exit_game(t_game *game);
int		handle_render(t_game *game);

void	_map_error(t_game *game, const char *msg);
void	_validate_walls(t_game *game);
void	_validate_path(t_game *game);
char	**_create_map_copy(t_game *game);
void	_free_map_copy(char **map_copy, int height);

void	init_game_constants(t_game *game);

#endif
