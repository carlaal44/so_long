/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:13:45 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/15 16:07:20 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"         // Para las funciones de libft
#include "get_next_line.h" // Para get_next_line
#include "ft_printf.h"     // Para ft_printf
#include "mlx.h"           // Para MinilibX
#include "so_long.h"       // Tu propia cabecera de so_long, si la tienes

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
