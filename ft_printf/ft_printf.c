/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:42:51 by ajari             #+#    #+#             */
/*   Updated: 2023/01/03 14:03:03 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(char c, va_list p)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = ft_putnbr_fd_p(va_arg(p, int), 1);
	else if (c == 's')
		count = ft_putstr_fd_p(va_arg(p, char *), 1);
	else if (c == 'c')
		count = ft_putchar_fd_p(va_arg(p, int), 1);
	else if (c == 'p')
	{
		ft_putstr_fd_p("0x", 1);
		count = ft_hexa_x(va_arg(p, size_t)) + 2;
	}
	else if (c == 'X')
		count = ft_hexa_xx(va_arg(p, unsigned int));
	else if (c == 'x')
		count = ft_hexa_x(va_arg(p, unsigned int));
	else if (c == 'u')
		count = ft_putnbr_fd_u(va_arg(p, unsigned int), 1);
	else
		count = ft_putchar_fd_p(c, 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(p, s);
	while (s && s[i])
	{
		if (s[i] != '%')
		{
			count += ft_putchar_fd_p(s[i], 1);
			i++;
		}
		else if (s[i] == '%' && s[i + 1])
		{
			count += ft_print(s[i + 1], p);
			i += 2;
		}
		else
			i++;
	}
	va_end(p);
	return (count);
}
