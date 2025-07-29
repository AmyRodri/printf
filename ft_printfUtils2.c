/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfUtils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:07:21 by amyrodri          #+#    #+#             */
/*   Updated: 2025/07/29 12:35:50 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignednbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 10)
		i += ft_unsignednbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
	i++;
	return (i);
}

int	ft_puthex_lower(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_puthex_lower(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
	i++;
	return (i);
}

int	ft_puthex_upper(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_puthex_upper(nbr / 16);
	write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	i++;
	return (i);
}
