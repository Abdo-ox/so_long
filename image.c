/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:23:11 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 19:48:13 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_w(t_mx m, void *im, int x, int y)
{
	mlx_put_image_to_window(m.mx, m.x_w, im, x, y);
}

void	fill_im(t_mx *m, int x, int y)
{
	m->image.door = mlx_xpm_file_to_image(m->mx, "./textures/door.xpm", &x, &y);
	m->image.b_g = mlx_xpm_file_to_image(m->mx, "./textures/b_g.xpm", &x, &y);
	m->image.dlr = mlx_xpm_file_to_image(m->mx, "./textures/dlr.xpm", &x, &y);
	m->image.wall = mlx_xpm_file_to_image(m->mx, "./textures/wall.xpm", &x, &y);
	m->image.p_d = mlx_xpm_file_to_image(m->mx, "./textures/p_down.xpm", &x,
			&y);
	m->image.g_w = mlx_xpm_file_to_image(m->mx, "./textures/g_w.xpm", &x, &y);
	m->image.black = mlx_xpm_file_to_image(m->mx, "./textures/black.xpm", &x,
			&y);
}

void	*choose_image(t_mx *m, char c)
{
	if (c == 'P')
		return (m->image.p_d);
	else if (c == 'E')
		return (m->image.door);
	else if (c == 'C')
		return (m->image.dlr);
	else if (c == '1')
		return (m->image.wall);
	return (m->image.b_g);
}

void	put_map_to_window(char **s, t_mx *m)
{
	void	*im;
	int		x;
	int		y;

	y = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x] != '\n')
		{
			im = choose_image(m, s[y][x]);
			if (!im)
				error("Error\n\t|--------------->❌\n\t",
					"->In import image 😎\n");
			put_image_to_w(*m, im, x * m->w, y * m->h);
			x++;
		}
		y++;
	}
}
