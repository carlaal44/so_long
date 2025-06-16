/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:18:30 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/16 12:53:33 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	_map_error(t_game *game, const char *msg)
{
	ft_printf("Error\n%s\n", msg);
	if (game->map)
		free_map(game);
	if (game->map_full_str_builder)
		free(game->map_full_str_builder);
	exit(1);
}

static void	_process_map_character_and_count(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		game->player_x = x;
		game->player_y = y;
	}
	else if (c == 'C')
		game->collectables++;
	else if (c != '0' && c != '1' && c != 'E')
		_map_error(game, "Carácter inválido en el mapa.");
}

static void	_validate_and_accumulate_line_data(t_game *game, char *line, int y)
{
	size_t	line_len;
	char	*temp_str;

	line_len = ft_strlen(line);
	if (line_len > 0 && line[line_len - 1] == '\n')
		line_len--;
	if (y == 0)
		game->width = line_len;
	else if (game->width != (int)line_len)
	{
		free(line);
		_map_error(game, "El mapa no es rectangular.");
	}
	temp_str = game->map_full_str_builder;
	game->map_full_str_builder = ft_strjoin(game->map_full_str_builder, line);
	free(temp_str);
	if (!game->map_full_str_builder)
	{
		free(line);
		_map_error(game, "Fallo de malloc al acumular mapa.");
	}
}

static void	_read_and_parse_all_lines(int fd, t_game *game, int *y_ptr)
{
	char	*line;
	int		x;

	line = get_next_line(fd);
	if (!line)
		_map_error(game, "El archivo del mapa está vacío.");
	while (line)
	{
		_validate_and_accumulate_line_data(game, line, *y_ptr);
		x = 0;
		while (line[x] && line[x] != '\n')
		{
			_process_map_character_and_count(game, line[x], x, *y_ptr);
			x++;
		}
		free(line);
		(*y_ptr)++;
		line = get_next_line(fd);
	}
}

void	read_map(char *file, t_game *game)
{
	int		fd;
	int		y;

	game->collectables = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->width = 0;
	game->height = 0;
	y = 0;
	game->map_full_str_builder = ft_strdup("");
	if (!game->map_full_str_builder)
		_map_error(game, "Fallo de malloc para el constructor de string.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		_map_error(game, "Error al abrir el mapa.");
	_read_and_parse_all_lines(fd, game, &y);
	close(fd);
	game->height = y;
	game->map = ft_split(game->map_full_str_builder, '\n');
	free(game->map_full_str_builder);
	game->map_full_str_builder = NULL;
	if (!game->map)
		_map_error(game, "Fallo de malloc al procesar el mapa final.");
	_validate_walls(game);
}
