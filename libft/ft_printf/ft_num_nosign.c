/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_nosign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:15:05 by carfern2          #+#    #+#             */
/*   Updated: 2024/12/07 15:44:02 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_num_nosign(unsigned int num)
{
	int		count;

	count = 0;
	if (num >= 10)
		count += ft_num_nosign(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}
