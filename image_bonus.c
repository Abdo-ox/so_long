/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:23:11 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 19:27:38 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_im(t_mx *m, int x, int y)
{
	m->image.door = xpm_file_to_img(m->mx, "./textures/door.xpm", x, y);
	m->image.d_o = xpm_file_to_img(m->mx, "./textures/door_o.xpm", x, y);
	m->image.d_s = xpm_file_to_img(m->mx, "./textures/door_s.xpm", x, y);
	m->image.b_g = xpm_file_to_img(m->mx, "./textures/b_g.xpm", x, y);
	m->image.dlr = xpm_file_to_img(m->mx, "./textures/dlr.xpm", x, y);
	m->image.wall = xpm_file_to_img(m->mx, "./textures/wall.xpm", x, y);
	m->image.p_d = xpm_file_to_img(m->mx, "./textures/p_down.xpm", x, y);
	m->image.p_u = xpm_file_to_img(m->mx, "./textures/p_up.xpm", x, y);
	m->image.p_r = xpm_file_to_img(m->mx, "./textures/p_right.xpm", x, y);
	m->image.p_l = xpm_file_to_img(m->mx, "./textures/p_left.xpm", x, y);
	m->image.nbr = xpm_file_to_img(m->mx, "./textures/nbr.xpm", x, y);
	m->image.i = xpm_file_to_img(m->mx, "./textures/i14.xpm", x, y);
	m->image.g_o = xpm_file_to_img(m->mx, "./textures/g_o.xpm", x, y);
	m->image.g_w = xpm_file_to_img(m->mx, "./textures/g_w.xpm", x, y);
	m->image.black = xpm_file_to_img(m->mx, "./textures/black.xpm", x, y);
}

void	image(t_mx *m)
{
	char	**p;
	char	**n;
	int		i;

	i = 0;
	p = malloc(sizeof(char *) * 13);
	n = malloc(sizeof(char *) * 16);
	while (i < 15)
	{
		if (i < 12)
		{
			p[i] = ft_strjoin(ft_strdup("./textures/dollar"), ft_itoa(i));
			p[i] = ft_strjoin(p[i], ft_strdup(".xpm"));
		}
		if (i == 12)
			p[i] = 0;
		n[i] = ft_strjoin(ft_strdup("./textures/i"), ft_itoa(i));
		n[i] = ft_strjoin(n[i], ft_strdup(".xpm"));
		i++;
	}
	n[i] = 0;
	m->imc = p;
	m->imi = n;
}

void	*choose_image(t_mx *m, char c)
{
	if (c == 'P')
		return (m->image.p_d);
	else if (c == 'E')
		return (m->image.door);
	else if (c == 'C')
		return (m->image.dlr);
	else if (c == 'I')
		return (m->image.i);
	else if (c == '1')
		return (m->image.wall);
	return (m->image.b_g);
}

void	put_aminate_image(t_mx *m, void *i, void *b, t_list *list)
{
	int	x;
	int	y;
	int	d;

	x = list->content->x;
	y = list->content->y;
	d = list->content->d;
	(void)i;
	(void)b;
	if (m->map[y][x + d] == 'P')
		game_over_or_win(11, m);
	if (m->map[y][x + d] == '0')
	{
		m->map[y][x] = '0';
		m->map[y][x + d] = 'I';
		put_image_to_w(*m, i, (x + d) * m->w, y * m->h);
		put_image_to_w(*m, b, x * m->w, y * m->h);
		list->content->x = x + d;
	}
	else
		m->i_data->content->d = -(m->i_data->content->d);
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
			put_image_to_w(*m, im, x * m->w, y * m->h);
			x++;
		}
		y++;
	}
}
