/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:40:26 by ajari             #+#    #+#             */
/*   Updated: 2023/01/03 13:40:31 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -1 * n;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd_p(int n, int fd)
{
	int	m;
	int	c;

	c = ft_count(n);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		m = n + 48;
		write(fd, &m, 1);
	}
	else
	{
		ft_putnbr_fd_p(n / 10, fd);
		ft_putnbr_fd_p(n % 10, fd);
	}
	return (c);
}
