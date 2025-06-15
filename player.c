/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:08 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 17:24:33 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

// Función auxiliar para verificar si un movimiento es válido
// No cuenta como función aparte para la norminette si es 'static'
// y es una función interna a este archivo.
static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->width ||
		new_y < 0 || new_y >= game->height)
		return (0); // Fuera de límites del mapa

	if (game->map[new_y][new_x] == '1')
		return (0); // Es una pared, no se puede mover

	// Aquí podrías añadir más validaciones:
	// - Si es 'E' (salida) y no ha recogido todos los coleccionables
	// - Colisiones con enemigos, etc.

	return (1); // Movimiento válido
}

int	move_player(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;

	ft_printf("Key pressed: %d\n", keycode);

	if (keycode == 53 || keycode == 65307)
		exit_game(game);

	// Determinar nueva posición basada en la tecla
	if (keycode == 119) // W (arriba)
		new_y--;
	else if (keycode == 115) // S (abajo)
		new_y++;
	else if (keycode == 97) // A (izquierda)
		new_x--;
	else if (keycode == 100) // D (derecha)
		new_x++;

	// Validar el movimiento antes de actualizar la posición
	if (is_valid_move(game, new_x, new_y))
	{
		// Actualiza el mapa: Quita 'P' de la posición antigua, pon '0' o 'C' si es coleccionable
		// Esto es crucial para que el jugador no deje "rastro" o se superponga.
		game->map[game->player_y][game->player_x] = '0'; // Cambia la posición anterior a suelo
		
		game->player_x = new_x;
		game->player_y = new_y;

		// Aquí se gestionaría la colisión con coleccionables y la salida
		// Por ahora, solo ponemos 'P' en la nueva posición.
		// Si la nueva posición es un coleccionable ('C'), deberías recogerlo
		// Si la nueva posición es la salida ('E'), deberías verificar si el juego termina
		game->map[game->player_y][game->player_x] = 'P'; // Mueve 'P' a la nueva posición

		game->moves++;
		ft_printf("Movimientos: %d\n", game->moves);
		draw_map(game); // Redibuja el mapa después del movimiento
	}
	else
	{
		ft_printf("Movimiento inválido (pared o fuera de límites)\n");
	}
	return (0);
}
