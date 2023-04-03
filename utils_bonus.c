/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:13:29 by ajari             #+#    #+#             */
/*   Updated: 2023/01/24 21:26:19 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image_to_w(t_mx m, void *im, int x, int y)
{
	if (im)
		mlx_put_image_to_window(m.mx, m.x_w, im, x, y);
	else
		error("Error\n\t|--------------->❌\n\t",
			"->In import image 😎\n");
}

int	is_allow(t_mx *m, int x, int y)
{
	if (m->map[y][x] == 'E' && m->n_c_token == m->n_of_c)
	{
		m->exit = 1;
		game_over_or_win(10, m);
		return (1);
	}
	if (m->map[y][x] == '1' || m->map[y][x] == 'E')
		return (0);
	return (1);
}

void	ft_freee(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_strdup_double(char **map)
{
	char	**dup;
	int		i;

	i = 0;
	while (map[i])
		i++;
	dup = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (map[i])
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	print_n_moves(t_mx *m)
{
	int		i;
	char	*t;

	m->n_moves++;
	i = m->n_moves;
	put_image_to_w(*m, m->image.nbr, 0, 0);
	t = ft_itoa(i);
	if (m->n_moves == 1)
	{
		ft_printf("%d MOVE\r", m->n_moves);
		mlx_string_put(m->mx, m->x_w, 0, 3, 0x00D10D, "Move");
		mlx_string_put(m->mx, m->x_w, 50, 5, 0xff0000, t);
	}
	else
	{
		ft_printf("%d MOVES\r", m->n_moves);
		mlx_string_put(m->mx, m->x_w, 0, 3, 0x00D10D, "Moves");
		mlx_string_put(m->mx, m->x_w, 55, 5, 0xff0000, t);
	}
	free(t);
}
