/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:18:30 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/18 11:34:21 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el mapa");
		exit(1);
	}
	map = malloc(sizeof(char *) * 100);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	game->map = map;
	game->height = i;
	game->width = ft_strlen(map[0]) - 1;
}
