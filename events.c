/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:04:30 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 17:04:33 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

// Función para salir del juego limpiamente.
// Debería liberar toda la memoria dinámica (mapa, imágenes, etc.).
int	exit_game(t_game *game)
{
	ft_printf("Saliendo del juego...\n");

	// 1. Destruir la ventana
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);

	// 2. Destruir las imágenes cargadas (solo si existen)
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_ground)
		mlx_destroy_image(game->mlx, game->img_ground);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);

	// 3. Destruir el display de MinilibX (importante en Linux)
	// Comenta esta línea si no estás en Linux o si mlx_init no crea un display
	// mlx_destroy_display(game->mlx);

	// 4. Liberar el mapa
	free_map(game); // Asumiendo que tienes esta función implementada

	// 5. Salir del programa
	exit(0);
	return (0); // Solo para satisfacer el prototipo de mlx_hook
}
