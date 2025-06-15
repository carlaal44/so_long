/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:38:48 by carfern2          #+#    #+#             */
/*   Updated: 2025/06/03 09:20:30 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	character;

	i = ft_strlen(s) - 1;
	character = (unsigned char)c;
	if (character == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (i >= 0)
	{
		if (s[i] == character)
			return ((char *)(i + s));
		i--;
	}
	return (NULL);
}
