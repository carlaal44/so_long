/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:32:02 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/17 15:01:11 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#define MAX_QUEUE_NODES 10000

static void	_enqueue(t_queue_node *queue, int *rear, int x, int y)
{
	if (*rear < MAX_QUEUE_NODES)
	{
		queue[*rear].x = x;
		queue[*rear].y = y;
		(*rear)++;
	}
}

static t_queue_node	_dequeue(t_queue_node *queue, int *front)
{
	t_queue_node	node;

	node = queue[*front];
	(*front)++;
	return (node);
}

static void	_perform_bfs_search(t_game *game, char **temp_map,
			int start_x, int start_y)
{
	t_queue_node	queue[MAX_QUEUE_NODES];
	t_queue_node	curr;
	t_bfs_data		data;
	int				nx;
	int				ny;

	data.front = 0;
	data.rear = 0;
	_enqueue(queue, &data.rear, start_x, start_y);
	temp_map[start_y][start_x] = 'V';
	while (data.front < data.rear)
	{
		curr = _dequeue(queue, &data.front);
		data.i = -1;
		while (++data.i < 4)
		{
			nx = curr.x + game->dirs.dx[data.i];
			ny = curr.y + game->dirs.dy[data.i];
			if (nx < 0 || nx >= game->width || ny < 0 || ny >= game->height
				|| temp_map[ny][nx] == '1' || temp_map[ny][nx] == 'V')
				continue ;
			temp_map[ny][nx] = 'V';
			_enqueue(queue, &data.rear, nx, ny);
		}
	}
}

static void	_count_reachable_elements(t_game *game, char **temp_map)
{
	int	x;
	int	y;

	game->path_reachable_collectables = 0;
	game->path_reachable_exit = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C' && temp_map[y][x] == 'V')
				game->path_reachable_collectables++;
			else if (game->map[y][x] == 'E' && temp_map[y][x] == 'V')
				game->path_reachable_exit++;
			x++;
		}
		y++;
	}
}

void	_validate_path(t_game *game)
{
	char	**temp_map;

	temp_map = _create_map_copy(game);
	if (!temp_map)
		_map_error(game, "Fallo de malloc al copiar el mapa para BFS.");
	_perform_bfs_search(game, temp_map, game->player_x, game->player_y);
	_count_reachable_elements(game, temp_map);
	_free_map_copy(temp_map, game->height);
	if (game->path_reachable_collectables != game->collectables \
		|| game->path_reachable_exit == 0)
	{
		_map_error(game,
			"No se puede alcanzar todos los coleccionables o la salida.");
	}
}
