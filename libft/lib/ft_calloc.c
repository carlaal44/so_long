/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:43:12 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/03 09:19:04 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t num, size_t n)
{
	void			*ptr;
	size_t			total_size;
	size_t			i;
	unsigned char	*p;

	total_size = num * n;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
