/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carfern2 <carfern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:05:40 by carfern2          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:15 by carfern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putnbr(int nb);
int		ft_putstr(char *s);
int		ft_printf(const char *format, ...);
int		ft_num_nosign(unsigned int num);
int		ft_punt_hexa(void *p);
int		ft_hexa_min(unsigned int num);
int		ft_hexa_mayus(unsigned int num);
int		handle_format(char specifier, va_list args);
#endif
