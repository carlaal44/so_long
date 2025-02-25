/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:13:45 by carfern2          #+#    #+#             */
/*   Updated: 2025/02/18 11:24:31 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *file, t_game *game)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el mapa");
		exit(1);
	}
	map = malloc(sizeof(char *) * 100);
	while ((line = get_next_line(fd)))
	{
		map[i++] = ft_strdup(line);
		free(line);
	}
	map[i] = NULL;
	close(fd);
	game->map = map;
	game->height = i;
	game->width = ft_strlen(map[0]) - 1;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Uso: ./so_long mapa.ber\n", 24);
		return (1);
	}
	read_map(argv[1], &game);
	start_game(&game);
	return (0);
}
