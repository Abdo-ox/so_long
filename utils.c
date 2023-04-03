/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:13:29 by ajari             #+#    #+#             */
/*   Updated: 2023/01/24 21:21:52 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_win(int k, t_mx *m)
{
	if (k == 53)
		exit(0);
	else if (k == 10)
	{
		m->stop = 1;
		mlx_put_image_to_window(m->mx, m->x_w, m->image.black, 0, 0);
		mlx_put_image_to_window(m->mx, m->x_w, m->image.g_w, m->w_w, m->h_w);
		ft_printf("🤣-->GAME WIN<--🤣\n");
	}
}

int	is_allow(t_mx *m, int x, int y)
{
	if (m->map[y][x] == 'E' && !m->n_of_c)
	{
		m->exit = 1;
		game_win(10, m);
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
	m->n_moves++;
	if (m->n_moves == 1)
		ft_printf("%d MOVE\n", m->n_moves);
	else
		ft_printf("%d MOVES\n", m->n_moves);
}
