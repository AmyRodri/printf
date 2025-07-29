/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfUtils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:59:54 by amyrodri          #+#    #+#             */
/*   Updated: 2025/07/29 14:26:19 by amyrodri         ###   ########.fr       */
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

int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
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

int	ft_putptr(void *p)
{
	int				i;
	unsigned long	endres;

	if (!p)
		return (write(1, "(nil)", 5));
	endres = (unsigned long)p;
	write(1, "0x", 2);
	i = 2;
	i += ft_puthex(endres);
	return (i);
}

int	ft_puthex(unsigned long endres)
{
	int	i;

	i = 0;
	if (endres >= 16)
		i += ft_puthex(endres / 16);
	write(1, &"0123456789abcdef"[endres % 16], 1);
	i++;
	return (i);
}
