/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:04:21 by carfern2          #+#    #+#             */
/*   Updated: 2024/12/07 13:43:44 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	process_specifier(const char *format, int *i, va_list args)
{
	int		result;

	(*i)++;
	if (format[*i])
	{
		result = handle_format(format[*i], args);
		if (result == -1)
			return (-1);
		(*i)++;
		return (result);
	}
	return (0);
}

static int	process_text(const char *format, int *i)
{
	int		result;

	result = ft_putchar(format[*i]);
	if (result == -1)
		return (-1);
	(*i)++;
	return (result);
}

static int	process_format(const char *format, int *i, va_list args)
{
	if (format[*i] == '%')
		return (process_specifier(format, i, args));
	else
		return (process_text(format, i));
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			total_chars;
	int			result;
	int			i;

	va_start(args, format);
	total_chars = 0;
	i = 0;
	while (format[i])
	{
		result = process_format(format, &i, args);
		if (result == -1)
			return (-1);
		total_chars += result;
	}
	va_end(args);
	return (total_chars);
}

int	handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_punt_hexa(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_num_nosign(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_hexa_min(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		return (ft_hexa_mayus(va_arg(args, unsigned int)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(specifier));
}
