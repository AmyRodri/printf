/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:56:28 by amyrodri          #+#    #+#             */
/*   Updated: 2025/07/29 14:59:15 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(const char c);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_putptr(void *p);
int	ft_puthex(unsigned long endres);
int	ft_putuint(unsigned int nbr);
int	ft_puthex_lower(unsigned int nbr);
int	ft_puthex_upper(unsigned int nbr);

#endif