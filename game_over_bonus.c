/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:41:59 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 19:27:55 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*xpm_file_to_img(void *m, char *s, int i, int j)
{
	s = mlx_xpm_file_to_image(m, s, &i, &j);
	return (s);
}

void	game_over_or_win(int k, t_mx *m)
{
	char	**s;
	int		x;
	int		y;

	x = m->x;
	y = m->y;
	s = m->map;
	if (k == 53)
		exit(0);
	if ((k == 123 && s[y][x - 1] == 'I') || (k == 124 && s[y][x + 1] == 'I')
		|| (k == 125 && s[y + 1][x] == 'I') || (k == 126 && s[y - 1][x] == 'I')
		|| k == 11)
	{
		m->stop = 1;
		mlx_put_image_to_window(m->mx, m->x_w, m->image.black, 0, 0);
		mlx_put_image_to_window(m->mx, m->x_w, m->image.g_o, m->w_w, m->h_w);
		ft_printf("🤣-->GAME OVER<--🤣\n");
	}
	else if (k == 10)
	{
		m->stop = 1;
		mlx_put_image_to_window(m->mx, m->x_w, m->image.black, 0, 0);
		mlx_put_image_to_window(m->mx, m->x_w, m->image.g_w, m->w_w, m->h_w);
		ft_printf("🤣-->GAME WIN<--🤣\n");
	}
}
