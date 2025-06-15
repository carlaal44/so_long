/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:18:30 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 16:07:25 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"         // Para las funciones de libft
#include "get_next_line.h" // Para get_next_line
#include "ft_printf.h"     // Para ft_printf
#include "mlx.h"           // Para MinilibX
#include "so_long.h"       // Tu propia cabecera de so_long, si la tienes

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
		size_t len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0'; 
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	game->map = map;
	game->height = i;
	game->width = ft_strlen(map[0]);
}
