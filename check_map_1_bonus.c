/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:38:41 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 19:30:30 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] != '1' && (!i || !j || !map[i + 1] || map[i][j
					+ 1] == '\n'))
				error("Error\n\t|--------------->❌\n\t",
					"->Your map doesn'not sorounder with 1 😎'");
			j++;
		}
		i++;
	}
}

void	check_c_i(char **s)
{
	int	x;
	int	y;
	int	c;
	int	i;

	y = 0;
	c = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x] != '\n')
		{
			if (s[y][x] == 'I')
				c++;
			if (s[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	if (!c || !i)
		error("Error\n\t|--------------->❌\n\t ",
			"->Your map doesn't containe C,I or both 😎'");
}

void	check_elements(char **s)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] != '\n')
		{
			if (s[i][j] == 'P' || s[i][j] == 'E')
				p++;
			else if (s[i][j] != '0' && s[i][j] != 'C' && s[i][j] != '1'
					&& s[i][j] != 'I')
				error("'Error\n\t|--------------->❌\n\t",
					"->Your map containe a strainger character 😎'");
			j++;
		}
		i++;
	}
	if (p != 2)
		error("'Error\n\t|--------------->❌\n\t",
			" ->Your map doesn't containe P, E or both 😎'");
	check_c_i(s);
}

void	error(char *s, char *m)
{
	ft_printf("%s %s", s, m);
	exit(0);
}
