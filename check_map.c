/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:41:15 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 19:46:51 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_m(int x, int y, char **s)
{
	char	c;

	c = s[y][x];
	if (c == 'P' || c == 'C' || c == '0')
		return (1);
	return (0);
}

void	check_one_by_one(int x, int y, int *a, char **m)
{
	if (m[y][x] == 'P')
		*a = 1;
	if (*a == 1)
		return ;
	m[y][x] = 'V';
	if (check_m(x + 1, y, m))
		check_one_by_one(x + 1, y, a, m);
	if (check_m(x - 1, y, m))
		check_one_by_one(x - 1, y, a, m);
	if (check_m(x, y + 1, m))
		check_one_by_one(x, y + 1, a, m);
	if (check_m(x, y - 1, m))
		check_one_by_one(x, y - 1, a, m);
}

void	check_path(char **map)
{
	char	**t;
	int		x;
	int		y;
	int		a;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				a = 0;
				t = ft_strdup_double(map);
				check_one_by_one(x, y, &a, t);
				ft_freee(t);
				if (!a)
					error("'Error\n\t|--------------->❌\n\t->there is no path",
						"to reach coin or door 😎'");
			}
			x++;
		}
		y++;
	}
}

int	check_map(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	check_wall(map);
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			error("'Error\n\t|--------------->❌\n\t",
				"->Your map doesn'not sorounder with 1 😎'");
		i++;
	}
	i--;
	if (map[i][0] == '\n')
		error("'Error\n\t|--------------->❌\n\t",
			"->Your map your map end with \\n 😎'");
	check_elements(map);
	check_path(map);
	return (1);
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
			error("'Error\n\t|--------------->❌\n\t ",
				"->check extention of your map file 😎");
	}
	return (1);
}
