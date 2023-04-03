/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_functiones_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:44:42 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 19:31:00 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_lines(int fd)
{
	char	*s;
	int		i;

	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (s == 0)
			break ;
		free(s);
		i++;
	}
	return (i);
}

int	count_number_of_c(t_mx m)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (m.map[i])
	{
		j = 0;
		while (m.map[i][j])
		{
			if (m.map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_extention(char *name)
{
	if (ft_strlen(ft_strnstr(name, ".ber", 4)) <= 4)
	{
		if (ft_strncmp(ft_strnstr(name, ".ber", 4), ".ber", 4))
			error("'Error\n\t|--------------->❌\n\t",
				"->check extention of your map file 😎");
	}
	else
	{
		if (ft_strncmp(ft_strnstr(name, ".ber", 4), ".ber",
				ft_strlen(ft_strnstr(name, ".ber", 4))))
			error("'Error\n\t|--------------->❌\n\t",
				"->check extention of your map file 😎");
	}
	return (1);
}
