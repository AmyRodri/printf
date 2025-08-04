/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfUtils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:59:54 by amyrodri          #+#    #+#             */
/*   Updated: 2025/07/31 16:46:39 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putptr(void *p)
{
	unsigned long	endres;
	int				i;
	int				count;
	char			hex[17];
	char			*base;

	if (!p)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	i = 0;
	endres = (unsigned long)p;
	base = "0123456789abcdef";
	while (endres > 0 || i == 0)
	{
		hex[i++] = base[endres % 16];
		endres /= 16;
	}
	count = i + 2;
	while (i--)
		write(1, &hex[i], 1);
	return (count);
}

int	ft_putnbr(int n)
{
	long int	nb;
	int			i;

	i = 0;
	nb = (long int)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb >= 10)
		i += ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	i++;
	return (i);
}

int	ft_putuint(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 10)
		i += ft_putuint(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
	i++;
	return (i);
}

int	ft_puthex_handle(unsigned int nbr, const char *format)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_puthex_handle(nbr / 16, format);
	if (*format == 'x')
	{
		write(1, &"0123456789abcdef"[nbr % 16], 1);
		i++;
	}
	if (*format == 'X')
	{
		write(1, &"0123456789ABCDEF"[nbr % 16], 1);
		i++;
	}
	return (i);
}
