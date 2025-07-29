/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:47:56 by amyrodri          #+#    #+#             */
/*   Updated: 2025/07/29 12:35:52 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list args, const char *format)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*format == 'u')
		return (ft_unsignednbr(va_arg(args, unsigned int)));
	if (*format == 'x')
		return (ft_puthex_lower(va_arg(args, unsigned int)));
	if (*format == 'X')
		return (ft_puthex_upper(va_arg(args, unsigned int)));
	if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	args;

	va_start(args, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			j += print_arg(args, &format[i + 1]);
			i += 2;
		}
		else
		{
			write(1, &format[i++], 1);
			j++;
		}
	}
	va_end(args);
	return (j);
}
