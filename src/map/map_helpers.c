/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:10:08 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/17 11:18:52 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_map_error(t_game *game, const char *msg)
{
	ft_printf("Error\n%s\n", msg);
	if (game->map)
		free_map(game);
	if (game->map_full_str_builder)
	{
		free(game->map_full_str_builder);
		game->map_full_str_builder = NULL;
	}
	exit(1);
}

char	**_create_map_copy(t_game *game)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (i > 0)
			{
				i--;
				free(copy[i]);
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[game->height] = NULL;
	return (copy);
}

void	_free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
