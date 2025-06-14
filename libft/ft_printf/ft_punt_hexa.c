/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punt_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:15:08 by carfern2          #+#    #+#             */
/*   Updated: 2024/12/07 15:41:46 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdint.h>

static int	ft_hexa_ptr(uintptr_t nbr)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_hexa_ptr(nbr / 16);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_punt_hexa(void *p)
{
	uintptr_t	addr;
	int			count;

	count = 0;
	if (p == NULL)
		return (ft_putstr("(nil)"));
	addr = (uintptr_t)p;
	count += ft_putstr("0x");
	if (addr == 0)
		count += ft_putchar('0');
	else
		count += ft_hexa_ptr(addr);
	return (count);
}
